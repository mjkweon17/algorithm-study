import sys

read = sys.stdin.readline
A, B = map(int, read().split())
C = int(read())

H = C // 60
M = C % 60

B = B + M
if B >= 60:
    B -= 60
    H += 1

A += H
A = A % 24
print(A, B)