'''
program that uses Wikipedia data about alcohol consumption
per capita and GDP of countries and dependencies per capita
to cross-tabulate GDP level (above average vs. below average)
vs. alcohol consumption level (above average vs. below average)
'''
import pandas as pd

#get the correct tables
alco_link = "https://en.wikipedia.org/wiki/List_of_countries_by_alcohol_consumption_per_capita"
alcohol = pd.read_html(alco_link)[0]

gdp_link = "https://en.wikipedia.org/wiki/List_of_countries_by_GDP_(PPP)_per_capita#Lists_of_countries_and_dependencies"
gdp = pd.read_html(gdp_link)[4]

#merge the tables and get the data about alcohol consumption and gdp
df = pd.merge(alcohol, gdp, left_on="Country", right_on="Country/Territory")

alco_gdp = df[["Country", "Total", "Int$"]]
alco_gdp = alco_gdp.set_index("Country")

mean_alco = alco_gdp["Total"].mean()
mean_gdp = alco_gdp["Int$"].mean()

high_alco_country = alco_gdp["Total"] > mean_alco
high_gdp_country = alco_gdp["Int$"] > mean_gdp

#cross-tabulate
cross_table = pd.crosstab(high_alco_country, high_gdp_country)

print(cross_table)
'''
It seems there may be a correlation between the two measures,
otherwise the proportion of Countries with above average alcohol
consumption would be almost equal in the two GDP measures 
(above and below average), and/or vive-versa. 
'''

