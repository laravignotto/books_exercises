'''
Program that displays a pie chart of the
U.S. states grouped by the first initial.
'''
import pandas as pd
import matplotlib.pyplot as plt
from collections import Counter

state_abbrev_link = "https://www.stateabbreviations.us/"
us_states = pd.read_html(state_abbrev_link)[1]
us_states.drop(us_states.index[0], inplace=True)

#get labels, e.g. states' initials
letters_freq = []
labels = []
for i, row in us_states.iterrows():
    first_letter = row['US States, Capitals, and Government Links'][0]
    if first_letter not in labels:
        labels.append(first_letter)
    letters_freq.append(first_letter)

#get sizes, e.g. how many times a given letter appears
letters_freq_counter = Counter(letters_freq)
sizes = []
for i in "".join(labels):
    sizes.append(letters_freq_counter[i])

#plot the pie chart
fig1, ax1 = plt.subplots()
plt.title("U.S. states by their initial")
ax1.pie(sizes, 
    labels=labels, 
    autopct=lambda p : '{:.0f}'.format(p * sum(sizes) / 100),
    startangle=90)
ax1.axis('equal') 

plt.show()