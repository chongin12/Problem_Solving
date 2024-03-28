n=int(input())
r=''
l=list(map(int,input().split()))
for a in l:
    if a>=300:r+="1 "
    elif a>=275:r+="2 "
    elif a>=250:r+="3 "
    else:r+="4 "
print(r)