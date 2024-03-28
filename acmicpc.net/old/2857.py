f=0
for i in range(5):
    if "FBI" in input():
        print(i+1, end=' ')
        f=1
if f==0:print("HE GOT AWAY!")