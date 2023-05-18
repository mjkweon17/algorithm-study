"""
import sys

read = sys.stdin.readline

for i in range(28):
    num = int(read())
    students[num] = True
for i in range(1, 31):
    if students[i] == False:
        print(i)

students = [i for i in range(1, 31)]
print(students)
"""

students = [i for i in range(1, 31)]

for _ in range(28):
    applied = int(input())
    students.remove(applied)

print(min(students))
print(max(students))