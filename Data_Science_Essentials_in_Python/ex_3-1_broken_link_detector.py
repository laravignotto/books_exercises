'''
Given a URL address, this program returns the broken links in the 
page.
This works faster than the solution in the book by making asynchronous 
requests with grequests (https://github.com/spyoungtech/grequests)
'''
import grequests
from urllib.request import urlopen
from bs4 import BeautifulSoup

#get the url
page_url = input("Which web page do you want to analyze? ")
try:
    page = urlopen(page_url)
except:
    print("Cannot open %s" % page_url)
    quit()

#get all the hlinks
soup = BeautifulSoup(page, features="lxml")

links = [(link["href"]) for link in soup.find_all("a") if link.has_attr("href")]

# This will notify about and print broken links
def exception_handler(request, exception):
    print("This link might be broken:")
    print(exception)

# Create a set of unsent Requests:
rs = (grequests.get(u) for u in links)

# Send them all at the same time:
grequests.map(rs, exception_handler=exception_handler)
