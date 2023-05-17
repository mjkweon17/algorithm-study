# input 예제
import sys

count = int(sys.stdin.readline())
data = []
for i in range(count):
    data.append(sum(map(int, sys.stdin.readline().split())))

for x in data:
    print(x)

# py의 으랏차차 차력쇼
for i in range(int(input())):print(f'#{i+1} '+str(sum(list(map(lambda x: int(x) if int(x)%2==1 else 0, input().split())))))