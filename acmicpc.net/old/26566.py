n=int(input())
for _ in range(n):
    a,b=map(float,input().split())
    c,d=map(float,input().split())
    if a/b > c*c*3.14/d:print("Slice of pizza")
    else:print("Whole pizza")