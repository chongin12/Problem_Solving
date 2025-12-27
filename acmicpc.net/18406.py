s=input()
a,b=0,0
for i in s[:len(s)//2]:
    a+=int(i)

for i in s[len(s)//2:]:
    b+=int(i)
if a==b:print("LUCKY")
else:print("READY")