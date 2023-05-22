import sys

read = sys.stdin.readline
N = int(read())

cnt = 0
for _ in range(N):
    word = read().strip()
    
    isGroup = True

    dict = {}
    for i in range(len(word)):
        if word[i] not in dict:
            dict[word[i]] = i
        else:
            if dict[word[i]] != i - 1:
                isGroup = False
                break
            else:
                dict[word[i]] = i
    
    if isGroup:
        cnt += 1

print(cnt)