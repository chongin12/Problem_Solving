a,b,c,x,y=map(int,input().split())
d=min(x,y)
print(min(a*x+b*y,a*(x-d)+b*(y-d)+c*d*2,c*max(x,y)*2))