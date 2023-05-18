import sys

read = sys.stdin.readline

N, M = map(int, read().split())

li = [0] * N
for i in range(M):
    i, j, k = map(int, read().split())
    for idx in range(i - 1, j):
        li[idx] = k

for i in li:
    print(i, end=" ")
