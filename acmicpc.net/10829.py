n=int(input())
s=""
while n>0:
    s+=f"{n%2}"
    n//=2
print(s[::-1])