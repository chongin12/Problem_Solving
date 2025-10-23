s=input()
w=input()
t=""
for i in s:
    if ord(i)>=ord('0') and ord(i)<=ord('9'):continue
    t+=i
if t.find(w)==-1:print(0)
else:print(1)