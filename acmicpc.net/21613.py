n=int(input())
rn=""
r=-1
for i in range(n):
    name=input()
    amount=int(input())
    if r<amount:
        r=amount
        rn=name
print(rn)