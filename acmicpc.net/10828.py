a = int(input())
x = []
for i in range(a):
    l = list(input().split())
    if l[0] == "push":
        x.append(l[1])
    elif l[0] == "top":
        if len(x) == 0:
            print("0")
        else:
            print(x[-1])
    elif l[0] == "size":
        print(len(x))
    elif l[0] == "empty":
        if len(x) == 0:
            print("0")
        else:
            print("1")
    elif l[0] == "pop":
        x.pop()