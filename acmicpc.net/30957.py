a=int(input())
s=input()
c=[s.count('B'), s.count('S'), s.count('A')]
if c[0]==c[1] and c[1]==c[2]:print("SCU")
else:
    if max(c)==c[0]:print("B", end='')
    if max(c)==c[1]:print("S", end='')
    if max(c)==c[2]:print("A", end='')