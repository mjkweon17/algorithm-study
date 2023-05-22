import sys

read = sys.stdin.readline
board = [[" " for _ in range(15)] for _ in range(5)]

for i in range(5):
    word = read().strip()
    for j in range(len(word)):
        board[i][j] = word[j]
for j in range(len(board[0])):
    for i in range(len(board)):
        if board[i][j] != " ":
            print(board[i][j], end="")