import sys

read = sys.stdin.readline
N, M = map(int, read().split())
A = []
B = []
for _ in range(N):
    A.append(list(map(int, read().split())))
for _ in range(N):
    B.append(list(map(int, read().split())))
C = [[0 for _ in range(M)] for _ in range(N)]
for i in range(len(C)):
    for j in range(len(C[0])):
        C[i][j] = A[i][j] + B[i][j]
for i in range(len(C)):
    for j in range(len(C[0])):
        print(C[i][j], end=" ")
    print("")