l,t=0,0
for i in range(9):
    a=input()
    if a=="Lion":l+=1
    else:t+=1
if l>t:print("Lion")
else:print("Tiger")