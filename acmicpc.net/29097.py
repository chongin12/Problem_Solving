n,m,k,a,b,c=map(int,input().split())
a=sorted([(-a*n,"Joffrey"),(-b*m,"Robb"),(-c*k,"Stannis")])
while True:
    if a[-1][0]>a[0][0]:a.pop()
    else:break
for i in a:
    print(i[1], end=' ')
print()