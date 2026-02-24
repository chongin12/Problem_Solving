n=int(input())
l1=set(list(map(str,input().split())))
l2=set(list(map(str,input().split())))
print(list(l1-l2)[0])