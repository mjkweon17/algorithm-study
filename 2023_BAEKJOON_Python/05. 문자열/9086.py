import sys

read = sys.stdin.readline

T = int(read().strip())

for _ in range(T):
    str = read().strip()
    print(str[0] + str[len(str) - 1])