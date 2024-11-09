arr=[0,1]
for i in range(500):
    arr.append(arr[-1]+arr[-2])
while True:
    a=int(input())
    if a==-1:break
    print(f"Hour {a}: {arr[a]} cow(s) affected")