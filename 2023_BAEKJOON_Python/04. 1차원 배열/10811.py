import sys

read = sys.stdin.readline

N, M = map(int, read().split())
basket = [i for i in range(0, N + 1)]

for _ in range(M):
    i, j = map(int, read().split())
    temp_li = []
    for k in range(j, i - 1, -1):
        temp_li.append(basket[k])
    for k in range(i, j + 1):
        basket[k] = temp_li[k - i]
for i in range(1, len(basket)):
    print(basket[i], end=" ")