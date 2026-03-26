n=int(input())
r=0
for i in range(n):
    s,d=map(str,input().split())
    h,m=map(int,s.split(':'))
    d=int(d)
    if h==18 and m+d>=60:
        r+=(60-m)*10+(m+d-60)*5
    elif h==6 and m+d>=60:
        r+=(60-m)*5+(m+d-60)*10
    elif h>=7 and h<19:
        r+=d*10
    else:
        r+=d*5
print(r)