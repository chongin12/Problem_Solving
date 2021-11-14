def t(a,b,c,p):return int(a*(b-p)**c)
def f(a,b,c,p):return int(a*(p-b)**c)

for _ in range(int(input())):
    a=list(map(int, input().split()))
    r = t(9.23076,26.7,1.835,a[0])+f(1.84523,75,1.348,a[1])+f(56.0211,1.5,1.05,a[2])+t(4.99087,42.5,1.81,a[3])+f(0.188807,210,1.41,a[4])+f(15.9803,3.8,1.04,a[5])+t(0.11193,254,1.88,a[6])
    print(r)