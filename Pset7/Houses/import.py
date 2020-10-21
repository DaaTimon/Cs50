# TODO
from cs50 import SQL
import sys
import csv

# getting access to SQL database
db = SQL("sqlite:///students.db")

# command line verification
if len(sys.argv) != 2:
    sys.exit('Check command line argument')

# open/verify csv
with open(sys.argv[1], "r") as csvfile:
    if csvfile.readable() == False:
        sys.exit('error reading csv')

# read csv line by line, list split by (,), simplified columns by removing 'names', and removed '\n'
    reader = csv.reader(csvfile, delimiter=",")

# auto skip header
    next(reader)

# defining line order
    for line in reader:
        name, house, birth = line

# parse name to make first, middle, last
        first, *middle, last = name.split(" ")
        if not middle:
            middle = None
        else:
            middle = middle

# insert data into db
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                   first, middle, last, house, int(birth))