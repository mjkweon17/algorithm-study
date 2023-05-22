import sys

read = sys.stdin.readline
A = []
for _ in range(9):
    li = list(map(int, read().split()))
    A.append(li)

big_row = 0
big_col = 0
big_num = A[0][0]

for i in range(9):
    for j in range(9):
        if A[i][j] > big_num:
            big_row = i
            big_col = j
            big_num = A[i][j]

print(big_num)
print(big_row + 1, big_col + 1)