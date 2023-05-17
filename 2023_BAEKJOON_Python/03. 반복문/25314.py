"""
N = int(input())

str = ""
for _ in range(N // 4):
    str += "long "
str += "int"

print(str)
"""

N = int(input())
num = int(n / 4)

print("long " * num, end="")
print("int")