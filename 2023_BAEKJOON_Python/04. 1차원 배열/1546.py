import sys

read = sys.stdin.readline
N = int(read())
li = list(map(int, read().split()))
max_value = max(li)
result = [i / max_value * 100 for i in li]
print(sum(result) / len(result))