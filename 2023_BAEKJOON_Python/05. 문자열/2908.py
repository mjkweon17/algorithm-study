import sys

A, B = sys.stdin.readline().split()
new_A = A[2] + A[1] + A[0]
new_B = B[2] + B[1] + B[0]
new_A = int(new_A)
new_B = int(new_B)
if(new_A > new_B):
    print(new_A)
else:
    print(new_B)