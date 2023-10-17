N,K=map(int,input().split())
l=list(map(int,input().split()))
def f(a):
    if a in range(0,5):
        return "1"
    if a in range(5,12):
        return "2"
    if a in range(12,24):
        return "3"
    if a in range(24,41):
        return "4"
    if a in range(41,61):
        return "5"
    if a in range(61,78):
        return "6"
    if a in range(78,90):
        return "7"
    if a in range(90,97):
        return "8"
    if a in range(97,101):
        return "9"
for i in l:
    print(f(i*100//N), end=' ')
