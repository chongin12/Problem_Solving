n,t=map(int,input().split())
t-=1
def f(x):return -x if x<0 else x
n*=2
print(n-f(n-1-t%(n*2-2)))