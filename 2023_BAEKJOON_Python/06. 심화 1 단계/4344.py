import sys

read = sys.stdin.readline

C = int(read())
for _ in range(C):
    score = list(map(int, read().split()))
    avg_score = sum(score[1:]) / float(score[0])
    cnt = 0
    for i in score[1:]:
        if i > avg_score:
            cnt += 1
    percentage = cnt / float(score[0]) * 100
    # print(round(percentage, 3), "%")
    print(f"{percentage:.3f}%")