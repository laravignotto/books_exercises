'''
program that uses the annual Canadian lynx trappings data
and reports total lynx trappings by decade (ten years),
sorted in the reverse order (most “productive” decade first)
'''
import pandas as pd

lynx_trappings_url = "https://vincentarelbundock.github.io/Rdatasets/csv/datasets/lynx.csv"

lynx_trappings = pd.read_csv(lynx_trappings_url)

#divide the dataset by decade, and delete 'incomplete' decades
lynx_trappings["Decade"] = (lynx_trappings["time"] // 10) * 10
lynx_trappings["count"] = 1
sum_lynx_decades = lynx_trappings.groupby("Decade").sum()
sum_lynx_decades = sum_lynx_decades.query("count == 10")

#sort the number of trappings in descending order
sum_lynx_decades.sort_values("value", ascending=False, inplace=True)
sum_lynx_decades.rename(columns={"value":"Trappings"}, inplace=True)

sum_lynx_decades["Trappings"].to_csv("lynx_trappings_by_decade2.csv", header=True)