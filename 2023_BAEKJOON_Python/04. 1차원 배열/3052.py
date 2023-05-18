import sys

read = sys.stdin.readline

remainder_list = [int(read()) % 42 for _ in range(10)]
unique_remainder = set(remainder_list)
print(len(unique_remainder))