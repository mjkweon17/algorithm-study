import sys

read = sys.stdin.readline
year = int(read())
converted_year = year - 2541 + 1998
print(converted_year)