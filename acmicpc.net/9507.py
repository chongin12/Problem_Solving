a=[1,1,2,4]
for i in range(4, 68):
    a.append(a[i-1]+a[i-2]+a[i-3]+a[i-4])
for _ in range(int(input())):
    s=int(input())
    print(a[s])