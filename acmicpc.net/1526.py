n=int(input())
def passs(x):
    while x>0:
        if x%10==4 or x%10==7:x//=10
        else:return False
    return True
while True:
    if passs(n):
        print(n)
        break
    n-=1