input()
l=list(map(int,input().split()))
a=int(input())
print(len([0 for i in l if i==a]))