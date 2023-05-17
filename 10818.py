import sys

read = sys.stdin.readline

N = int(read())
arr = list(map(int, read().split()))
print(min(arr), max(arr))