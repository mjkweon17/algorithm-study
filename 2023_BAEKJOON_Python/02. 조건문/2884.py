import sys

H, M = map(int, sys.stdin.readline().split())
if M < 45:
    M = 60 + M - 45
    if H == 0:
        H = 23
    else:
        H -= 1
else:
    M -= 45

print(H, M)