q=10
r=0
sum=0
s=input()
for i in range(10):
    if s[i]=='?':
        q=10-i
    elif s[i]=='X':
        sum+=10*(10-i)
    else:
        sum+=int(s[i])*(10-i)

for i in range(11):
    if (sum+q*i)%11==0:
        if i==10:
            if q==1:
                print('X')
                exit(0)
        else:
            print(i)
            exit(0)
print("-1")