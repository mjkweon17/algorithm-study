import sys

li = ['c=','c-','dz=','d-','lj','nj','s=','z=']
word = sys.stdin.readline().strip()
for i in li:
    word = word.replace(i, '*')
print(len(word))


"""
import sys

word = sys.stdin.readline().strip()
cnt = 0
i = 0

while i < len(word):

    cnt += 1

    if word[i] == "-":
        if i >= 1 and (word[i - 1] == "c" or word[i - 1] == "d"):
            cnt -= 1
    elif word[i] == "=":
        if i >= 2 and (word[i - 2] == "d" and word[i - 1] == "z"):
            cnt -=2
        elif i >= 1 and (word[i - 1] == "c" or word[i - 1] == "s" or word[i - 1] == "z"):
            cnt -= 1
    elif word[i] == "j":
        if i >= 1 and (word[i - 1] == "l" or word[i - 1] == "n"):
            cnt -= 1

    i += 1

print(cnt)
"""