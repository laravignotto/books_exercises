'''
Program that reports some basic statistical measures of the closing
values of the S&P 500 stock index: the mean, standard deviation, 
skewness, and correlation between the closing values and trading 
volume in the twenty-first century.
The dataset was downloaded from
finance.yahoo.com/q/hp?s=^GSPC+Historical+Prices
and saved as dataset.csv
'''
import pandas as pd
from scipy.stats import pearsonr

stock = pd.read_csv("dataset.csv").set_index('Date')

close_mean = stock['Close'].mean()
close_sd = stock['Close'].std()
close_skewness = stock['Close'].skew()
print("Mean: %s\nStandard Deviation: %s\nSkewness: %s" % (close_mean, close_sd, close_skewness))

corr, pval = pearsonr(stock['Close'], stock['Volume'])
print("Correlation: %s\np-value: %s\n" % (corr, pval))