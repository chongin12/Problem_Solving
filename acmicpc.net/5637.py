r=""
while True:
    s=""
    a=input()
    for i in a:
        if (ord(i)>=ord('A') and ord(i)<=ord('Z')) or (ord(i)>=ord('a') and ord(i)<=ord('z')) or i=='-':
            s+=i
        else:
            if len(r)<len(s):r=s
            s=""
    if len(r)<len(s):r=s
    if s=="E-N-D":break
print(r.lower())