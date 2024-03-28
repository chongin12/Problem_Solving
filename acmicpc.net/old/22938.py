q,w,e=map(int,input().split())
a,s,d=map(int,input().split())
if (q-a)**2+(w-s)**2<(e+d)**2:print("YES")
else:print("NO")