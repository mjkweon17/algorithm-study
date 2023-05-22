import sys

read = sys.stdin.readline

dict = { "A+": 4.5, "A0": 4.0, "B+": 3.5, "B0": 3.0, "C+": 2.5, "C0": 2.0, "D+": 1.5, "D0": 1.0, "F": 0.0}

total_weight = 0    #전체 학점
total_grade = 0     #등급 총합
for _ in range(20):
    class_name, weight, grade = map(str.strip, read().split())
    weight = float(weight)  #학점
    if grade == 'P':
        continue
    total_weight += weight
    total_grade += dict[grade] * weight
if total_weight == 0:
    print(format(0, ".6f"))
else:
    print(round(total_grade / total_weight, 6))