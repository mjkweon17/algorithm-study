import sys

read = sys.stdin.readline
X = int(read())
N = int(read())

sum = 0
for _ in range(N):
    a, b = map(int, read().split())
    sum += a * b

if sum == X:
    print("Yes")
else:
    print("No")