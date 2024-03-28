a,b,c=map(int,input().split("-"))
n=int(input())
c+=n
if c>30:
    b+=(c-1)//30
    c=(c-1)%30+1
if b>12:
    a+=(b-1)//12
    b=(b-1)%12+1
print(f"{a}-{b:02}-{c:02}")