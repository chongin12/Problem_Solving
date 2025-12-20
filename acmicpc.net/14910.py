l=list(map(int,input().split()))
prev=-10000000
for i in l:
    if i>=prev:
        prev=i
    else:
        print("Bad")
        exit(0)
print("Good")