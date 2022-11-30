import csv
import re
from sys import argv, exit

# getting the required csv file 

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

csvfile = open(argv[1], newline="") 
databaseReader = csv.reader(csvfile, delimiter=",", quotechar="|")
# to compute the longest run of consecutive repeats of the STR in the DNA sequence to identify.
for i, r in enumerate(databaseReader):
    if i == 0:
        txtfile = open(argv[2], "r") 
        line = next(txtfile)
        longest_strings = []
        for i in range(1, len(r)):
            pattern = r[i]
            matches = (
                match[0] for match in re.finditer(fr"(?:{pattern})+", line)
            )
            try:
                longest = int(len(max(matches, key=len)) / len(pattern))
                longest_strings.append(longest)
            except ValueError:
                longest_strings.append(0)
    else:
        # print out the name of the matching individual when STR Match found
        list_database_strings = list(map(int, r[1:]))
        if list_database_strings == longest_strings:
            print(r[0])
            break
        
# when STR match not found
else:
    print("No match")
