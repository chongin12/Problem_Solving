a,b,c=map(int,input().split('-'))
if b<9 or (b==9 and c<=16):print("GOOD")
else:print("TOO LATE")