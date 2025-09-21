n=int(input())
for i in range(n):
    a=i+1
    if a%3==0 and a%5==0:
        print("DeadMan")
    elif a%3==0:
        print("Dead")
    elif a%5==0:
        print("Man")
    else:print(a, end=' ')
