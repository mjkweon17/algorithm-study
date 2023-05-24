import sys

read = sys.stdin.readline
T = int(read())

for _ in range(T):
    C = int(read())
    print(C // 25, end=" ")
    C -= 25 * (C // 25)
    print(C // 10, end=" ")
    C -= 10 * (C // 10)
    print(C // 5, end=" ")
    C -= 5 * (C // 5)
    print(C // 1)