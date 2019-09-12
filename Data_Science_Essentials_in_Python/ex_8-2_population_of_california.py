'''
Program that uses U.S. Census Bureau data 4 to display how 
the population of California (relative to the total population of the United States) changed between 2001 and 2009.
The dataset was retrieved from here:
https://web.archive.org/web/20120110174933/http://www.census.gov/popest/data/state/totals/2009/tables/NST-EST2009-02.csv
The file used can also be downloaded from here:
https://cpaste.cc/tsI0XUWGo5
'''
import matplotlib, matplotlib.pyplot as plt
import pandas as pd
import numpy as np

data = pd.read_csv("population_change.csv", thousands=',')
data.iloc[9,0] = 'California'

#get a dataframe with only United States and California
us_cali = data.iloc[[0,9], [0,1,2,3,4,5,6,7,8,9]]
us_cali.columns = ["Area", "2009", "2008", "2007", "2006", "2005", "2004", "2003", "2002", "2001"]
us_cali.set_index('Area', inplace=True)
us_cali = us_cali[us_cali.columns[::-1]]

#plot
years = list(range(2001,2010)) 
areas = ("United States", "California")

matplotlib.style.use("ggplot")

x1 = us_cali.loc["United States"]
x2 = us_cali.loc["California"]

#FIRST PLOT: lines
fig, ax1 = plt.subplots()

color = 'tab:red'
ax1.set_xlabel('year')
ax1.set_ylabel('US pop (*10^8)', color=color)
ax1.plot(years, x1, color=color)
ax1.tick_params(axis='y', labelcolor=color)
ax1.set_yticks([min(x1), 290000000, 295000000, 300000000, 305000000, max(x1)])

ax2 = ax1.twinx()

color = 'tab:blue'
ax2.set_ylabel('CA pop (*10^7)', color=color)
ax2.plot(years, x2, color=color)
ax2.tick_params(axis='y', labelcolor=color)
ax2.set_yticks([min(x2), 34500000, 35000000, 35500000, 36000000, 36500000, max(x2)])

fig.tight_layout()
plt.show()

#SECOND PLOT: bars
# fig, ax1 = plt.subplots()
# X = np.array(years)

# color = 'tab:red'
# ax1.set_xlabel('year')
# ax1.set_ylabel('US pop (*10^8)', color=color)
# ax1.bar(X - 0.15, x1, 0.3, color=color)

# ax2 = ax1.twinx()

# color = 'tab:blue'
# ax2.set_ylabel('CA pop (*10^7)', color=color)
# ax2.bar(X + 0.15, x2, 0.3, color=color)

# plt.show()
