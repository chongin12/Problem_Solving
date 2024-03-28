input()
a=sorted(list(map(int,input().split())))
r=0
for i in a:r+=i
print(r-a[-1])