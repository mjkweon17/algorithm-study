import sys

num = 0
N, B = map(str.strip, sys.stdin.readline().split())
# B진법, 수 N
B = int(B)
for i in range(len(N)):
    if ord(N[i]) >= ord('0') and ord(N[i]) <= ord('9'):
        num += (B ** (len(N) - 1 - i)) * int(N[i])
    else:
        digit_num = ord(N[i]) -ord('A') + 10
        num += (B ** (len(N) - 1 - i)) * digit_num
print(num)