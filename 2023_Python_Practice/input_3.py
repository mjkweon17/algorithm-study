# py의 으랏차차 차력쇼
for i in range(int(input())):print(f'#{i+1} '+str(sum(list(map(lambda x: int(x) if int(x)%2==1 else 0, input().split())))))