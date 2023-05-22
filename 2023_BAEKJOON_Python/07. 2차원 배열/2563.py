import sys

read = sys.stdin.readline

paper = [[0 for _ in range(100)] for _ in range(100)]
pNum = int(read())
for _ in range(pNum):
    left, bottom = map(int, read().split())
    for i in range(left, left + 10):
        for j in range(bottom, bottom + 10):
            paper[i][j] = 1
flattened_matrix = [element for row in paper for element in row]
cnt = flattened_matrix.count(1)
print(cnt)