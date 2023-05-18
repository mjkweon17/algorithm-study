import sys

read = sys.stdin.readline

total = 0

N = int(read())
str = read().strip()
for i in str:
    total += int(i)
print(total)