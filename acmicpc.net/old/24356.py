t1,m1,t2,m2=map(int,input().split())
mm1=t1*60+m1
mm2=t2*60+m2
if mm1>mm2:
    print(mm2-mm1+60*24, end=' ')
    print((mm2-mm1+60*24)//30)
else:
    print(mm2-mm1, end=' ')
    print((mm2-mm1)//30)