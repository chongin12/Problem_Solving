n,m=map(int,input().split())
arr=[0]
for i in range(n):
    arr.append(int(input()))
for i in range(1,m+1):
    for j in range(2,n+1):
        if arr[j-1]%i>arr[j]%i:
            arr[j-1],arr[j]=arr[j],arr[j-1]
for i in range(n):
    print(arr[i+1])