a,b,c,d,e,f=map(int,input().split())
x=(b*f-e*c)//(b*d-a*e)
if b!=0:
    y=(-a*x+c)//b
else:
    y=(-d*x+f)//e
print(x,y)