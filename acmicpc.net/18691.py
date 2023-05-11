t=int(input())
for i in range(t):
    a,b,c=map(int,input().split())
    print(max(0,(c-b)*(a*2-1)))