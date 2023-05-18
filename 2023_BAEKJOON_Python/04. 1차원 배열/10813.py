import sys

read = sys.stdin.readline

N, M = map(int, read().split())
basket = [0] * (N + 1)
for i in range(len(basket)):
    basket[i] = i
for i in range(M):
    i, j = map(int, read().split())
    temp = basket[i]
    basket[i] = basket[j]
    basket[j] = temp
for i in range(1, N + 1):
    print(basket[i])