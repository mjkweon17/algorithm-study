import sys

read = sys.stdin.readline

N, X = map(int, read().split())
li = list(map(int, read().split()))

cnt = 0
for i in range(N):
    if li[i] < X:
        print(li[i], end=" ")