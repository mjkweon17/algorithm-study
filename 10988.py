word = input()
word_len = len(word)
fail = False
for i in range(word_len // 2):
    if word[i] != word[word_len - 1 - i]:
        fail = True
        break
if fail:
    print(0)
else:
    print(1)