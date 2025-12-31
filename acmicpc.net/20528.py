n=int(input())
l=list(map(str,input().split()))
for i in l:
    if i[0][0]!=l[0][0]:
        print("0")
        exit(0)
print("1")