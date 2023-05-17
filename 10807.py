import sys

read = sys.stdin.readline

N = int(read())
arr = list(map(int, read().split()))
v = int(read())
print(arr.count(v))