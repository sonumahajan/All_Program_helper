from collections import Counter
string = input()
cnt = Counter(string)
for i in cnt:
    print(i,":" , cnt[i]) # occurrence