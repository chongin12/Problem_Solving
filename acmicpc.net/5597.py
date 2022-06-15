s=set()
for i in range(30):
    s.add(i+1)
for i in range(28):
    s.remove(int(input()))
for i in list(s):
    print(i)