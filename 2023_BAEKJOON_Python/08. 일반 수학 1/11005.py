import sys

# N: 10진수 수, B: 진법
N, B = map(int, sys.stdin.readline().split())
converted_num = []
while True:
    converted_num.append(N % B)
    if N // B == 0:
        break
    N = N // B
for i in range(len(converted_num)):
    if converted_num[i] > 9:
        converted_num[i] = chr(converted_num[i] - 10 + ord('A'))
for i in converted_num[::-1]:
    print(i, end="")