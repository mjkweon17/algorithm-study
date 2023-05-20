cnt = [0] * (ord('z') - ord('a') + 1)
word = input()
for i in range(len(word)):
    if word[i] >= 'a' and word[i] <= 'z':
        cnt[ord(word[i]) - ord('a')] += 1
    else:
        cnt[ord(word[i]) - ord('A')] += 1

have_same = False
max_index = 0
for i in range(1, len(cnt)):
    if cnt[i] > cnt[max_index]:
        max_index = i
        have_same = False
    elif cnt[i] == cnt[max_index]:
        have_same = True
if have_same:
    print('?')
else:
    print(chr(max_index + ord('A')))


"""
1. 200ms (내가 한 건 376ms)

word = input().upper()  # 입력 받음

count_dict = {}
for alphabet in word:
    count_dict[alphabet] = count_dict.get(alphabet, 0) + 1

max_count = max(count_dict.values())
most_frequent_alphabets = [alphabet for alphabet, count in count_dict.items() if count == max_count]

if len(most_frequent_alphabets) == 1:
    print(most_frequent_alphabets[0])
else:
    print('?')


"""


"""
2. 84ms

word = input().upper()
word_list = list(set(word))

cnt = []
for i in word_list:
  count = word.count
  cnt.append(count(i))

if cnt.count(max(cnt)) > 1:
  print("?")

else:
  print(word_list[(cnt.index(max(cnt)))])
"""