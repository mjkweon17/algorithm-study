import sys

read = sys.stdin.readline

while True:
    try:
        A, B = map(int, read().split())
    except:
        break
    print(A + B)