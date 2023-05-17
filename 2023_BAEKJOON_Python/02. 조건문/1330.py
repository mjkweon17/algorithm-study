import sys

read = sys.stdin.readline

A, B = map(int, read().split())

if(A > B):
    print(">")
elif(A < B):
    print("<")
else:
    print("==")