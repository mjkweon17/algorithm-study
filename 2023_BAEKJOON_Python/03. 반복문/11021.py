import sys

read = sys.stdin.readline

T = int(read())
for i in range(T):
    A, B = map(int, read().split())
    print(f"Case #{i + 1}: {A + B}")