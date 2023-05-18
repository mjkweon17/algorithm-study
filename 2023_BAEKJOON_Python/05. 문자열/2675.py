import sys

read = sys.stdin.readline

T = int(read())

for _ in range(T):
    R, my_str = map(str, read().split())
    R = int(R)
    new_str = ""
    for i in range(len(my_str)):
        new_str += my_str[i] * R
    print(new_str)