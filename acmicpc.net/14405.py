s=input()
while True:
    if len(s)==0:break
    if s[0:2]=="pi":
        s=s[2:]
    elif s[0:2]=="ka":
        s=s[2:]
    elif s[0:3]=="chu":
        s=s[3:]
    else:
        print("NO")
        exit(0)
print("YES")