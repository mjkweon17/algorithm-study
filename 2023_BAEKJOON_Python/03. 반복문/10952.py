import sys

read = sys.stdin.readline

while True:
    A, B = map(int, read().split())
    if A == 0 and B == 0:
        break
    print(A + B)