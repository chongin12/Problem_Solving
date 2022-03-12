L = int(input())
a = list(map(int, input().split()))
n = int(input())
small=[]
big=[]
result=0
k = 1
a.sort()
for i in a:
    if i > n:
        big.append(i)
    elif i < n:
        small.append(i)
    elif i == n:
        k = 0


x = n - small[-1] - 1 # 왼쪽으로 갈 수 있는 칸수
y = big[0] - n - 1 # 오른쪽으로 갈 수 있는 칸수
result = (x+1) * (y+1) - 1


if k == 0:
    print(0)
else:
    print(result)
