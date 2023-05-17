# input 예제
import sys

count = int(sys.stdin.readline())
data = []
for i in range(count):
    data.append(sum(map(int, sys.stdin.readline().split())))

for x in data:
    print(x)