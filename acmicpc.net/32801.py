n,a,b=map(int,input().split())
F,B,fb=0,0,0
for i in range(1,n+1):
    if i%a==0 and i%b==0:fb+=1
    elif i%a==0:F+=1
    elif i%b==0:B+=1
print(F,B,fb)