import sys

read = sys.stdin.readline

N = int(read())

count_array = [0] * 10001
for _ in range(N):
    num = int(read())
    count_array[num] += 1

for i in range(len(count_array)):
    if count_array[i] != 0:
        for j in range(count_array[i]):
            print(i)