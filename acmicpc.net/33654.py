n=int(input())
l=list(map(int,input().split()))
a=[]
for i in l:
    if len(a)==0:a.append(i)
    elif a[-1]<=i:a.append(i)
for i in a:
    print(i, end=' ')
print()