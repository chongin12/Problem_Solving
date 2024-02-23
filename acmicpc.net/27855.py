a,b=map(int,input().split())
A=a*3+b
c,d=map(int,input().split())
B=c*3+d
if A>B:print(f"1 {A-B}")
elif A<B:print(f"2 {B-A}")
else:print("NO SCORE")