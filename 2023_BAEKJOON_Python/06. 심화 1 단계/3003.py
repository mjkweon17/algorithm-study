import sys
correct_list = [1, 1, 2, 2, 2, 8]
input_list = list(map(int, sys.stdin.readline().split()))
for i in range(len(correct_list)):
    print(correct_list[i] - input_list[i], end=" ")