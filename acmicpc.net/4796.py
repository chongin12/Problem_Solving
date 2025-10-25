i=0
while True:
    i+=1
    l,p,v=map(int,input().split())
    if l+p+v==0:break
    print(f"Case {i}: {(v//p)*l+min(v%p,l)}")