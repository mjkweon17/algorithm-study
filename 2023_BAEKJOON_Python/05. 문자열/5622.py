num = input()
total = 0
for i in num:
    if i <= 'C':
        total += 3
    elif i <= 'F':
        total += 4
    elif i <= 'I':
        total += 5
    elif i <= 'L':
        total += 6
    elif i <= 'O':
        total += 7
    elif i <= 'S':
        total += 8
    elif i <= 'V':
        total += 9
    elif i <= 'Z':
        total += 10
print(total)