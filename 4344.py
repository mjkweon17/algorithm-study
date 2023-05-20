import sys

read = sys.stdin.readline

C = int(read())
for _ in range(C):
    score = list(map(int, read().split()))
    avg_score = sum(score[1:]) / float(score[0])
    for i in score[1:]:
        