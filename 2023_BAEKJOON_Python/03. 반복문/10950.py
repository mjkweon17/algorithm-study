import sys

read = sys.stdin.readline
T = int(read())
for _ in range(T):
    num1, num2 = map(int, read().split())
    print(num1 + num2)