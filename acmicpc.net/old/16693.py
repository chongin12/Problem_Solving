a,p1=map(float,input().split())
r,p2=map(float, input().split())
if p1/a > p2/(r*r*3.1415926535):
    print("Whole pizza")
else:print("Slice of pizza")