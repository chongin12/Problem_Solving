s=input()
if s=="0":
    print("1")
    exit(0)
k=""

for i in range(len(s)):k+='1'
if k<=s:print(len(s))
else:print(len(s)-1)