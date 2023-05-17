li = []
for i in range(9):
    li.append(int(input()))

max_index = 0
for i in range(len(li)):
    if li[max_index] < li[i]:
        max_index = i

print(li[max_index])
print(max_index + 1)