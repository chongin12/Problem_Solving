s=input()
h,g=0,0
for i in s:
    if i in "SAD":
        g+=1
    if i in "HAPPY":
        h+=1
if h+g==0:print("50.00")
else:print(f"{h/(h+g)*100:.2f}")