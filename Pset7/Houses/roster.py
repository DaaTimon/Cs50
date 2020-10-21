# TODO
from cs50 import SQL
import sqlite3
import sys
import csv

# getting access to SQL database
db = SQL("sqlite:///students.db")

# command line verification
if len(sys.argv) != 2:
    sys.exit('Check command line argument')

n = (sys.argv[1])

for result in db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last", n):

    if (result['middle'] == None):
        print(result['first'], end=' ')
        print(result['last'], end=', ')
        print('born', end=' ')
        print(result['birth'])
    else:
        print(result['first'], end=' ')
        print(result['middle'], end=' ')
        print(result['last'], end=', ')
        print('born', end=' ')
        print(result['birth'])