a=int(input())
b=int(input())
if 60+b<=a:
    print(1500*(60+b)+3000*(a-b-60))
else:
    print(1500*a)