T = int(input())
for i in range(T):
    numbers = []
    sum = 0
    for j in range(10):
        num = int(input())
        numbers.append(num)
        for k in numbers:
            if(k % 2):
                sum += k
    print(sum)