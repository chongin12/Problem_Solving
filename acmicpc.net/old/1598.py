a,b=map(int,input().split())
a-=1
b-=1
print(abs(b//4-a//4)+abs(b%4-a%4))