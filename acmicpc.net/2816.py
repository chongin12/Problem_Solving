n=int(input())
a,b=0,0
for i in range(n):
    s=input()
    if s=="KBS1":a=i
    if s=="KBS2":b=i
r=""
if a>b:b+=1
for i in range(a):
    r+="1"
for i in range(a):
    r+="4"
for i in range(b):
    r+="1"
for i in range(b-1):
    r+="4"
print(r)