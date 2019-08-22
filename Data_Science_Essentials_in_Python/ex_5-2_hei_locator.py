'''
Program that reports ten higher education institutions (HEIs) 
that are the closest geographically to the point defined by the 
mean latitude and mean longitude of all HEIs in the dataset

Dataset downloaded (with help from the Internet Archive) from
https://web.archive.org/web/20150906052954/https://inventory.data.gov/dataset/032e19b4-5a90-41dc-83ff-6e4cd234f565/resource/38625c3d-5388-4c16-a30f-d105432553a4
'''
import csv
import numpy as np
from numpy import linalg as LA
from collections import Counter

with open("postscndryunivsrvy2013dirinfo.csv", newline='', encoding = "ISO-8859-1") as infile:
    data = list(csv.reader(infile, delimiter=',', quotechar='"'))

#get LATITUDE and LONGITUD index
lon_index = data[0].index("LONGITUD")
lat_index = data[0].index("LATITUDE")

#get all latitude and longitude values
coordinates = np.array([float(row[lon_index]) for row in data[1:]] + 
                        [float(row[lat_index]) for row in data[1:]])

#change shape of the coordinates array. Now it's a 2d array with 2 rows:
#the 1st one contains longitudes, the 2nd one contains latitudes
coordinates = coordinates.reshape(2, -1)

latitude_mean = np.mean(coordinates[0])
longitude_mean = np.mean(coordinates[1])
coord_mean = np.array([latitude_mean, longitude_mean])

inst_index = data[0].index("INSTNM")
institutes_names = np.array([row[inst_index] for row in data[1:]])

distances = []
for coord in coordinates.T:
    dist = LA.norm(coord-coord_mean)
    distances.append(dist)

distances = np.array(distances)
k = 10
#get the indices of the distances in order: the first 10 are the indices of the smallest numbers
smallest_dist_idx = np.argpartition(distances, k)
#get just the indices of the 10 smallest dists
ten_min_dist = (smallest_dist_idx[0:k])

print("The point defined by the mean latitude and mean longitude of all HEIs in the data set is %s" % coord_mean)
print("These are the 10 (unordered) HEIs that are geographically closer to the mean point:\n")

n = 1
for i in ten_min_dist:
    print("%s) %s, distance: %s" % (n, institutes_names[i], distances[i]))
    n += 1