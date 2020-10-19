import sys
import csv
import re

# command line verification
if len(sys.argv) != 3:
    sys.exit('Check command line argument')

# open/verify csv
with open(sys.argv[1], "r") as csvfile:
    if csvfile.readable() == False:
        sys.exit('error reading csv')

# read csv line by line, list split by (,), simplified columns by removing 'names', and removed '\n'
    read_csv = csvfile.readline()
    header = list(read_csv.split(','))
    header.remove('name')
    header[len(header) - 1] = header[len(header) - 1].rstrip('\n')

# open/verify sequence and read sequence
with open(sys.argv[2], "r") as sequence:
    if sequence.readable() == False:
        sys.exit('error reading sequence')

    read_sequence = sequence.read()

# storing max str counts for each str type in list
maxstr_list = []

# checking str(s) match
for i in range(0, len(header)):
    j = 0
    str_count = 0
    maxstr_count = 0
    while j < len(read_sequence):
        if re.match(header[i], read_sequence[j:]):
            str_count += 1
            j += len(header[i])
        else:
            if str_count > maxstr_count:
                maxstr_count = str_count

            str_count = 0
            j += 1

# add maxstr_count to maxstr_list
    maxstr_list.append(maxstr_count)

# reopen csv
with open(sys.argv[1], "r") as csvfile:
    if csvfile.readable() == False:
        sys.exit('Error reading csv')

# create tempcsv to hold comparison value then compare str counts to databases by iterating over each variable
    read_tempcsv = csv.reader(csvfile)
    row = next(read_tempcsv)
    matched = False
    for row in read_tempcsv:
        name = row[0]
        del row[0]
        rowInt = list(map(int, row))
        if rowInt == maxstr_list:
            print(name)
            matched = True
            break
    if matched == False:
        print("No match")