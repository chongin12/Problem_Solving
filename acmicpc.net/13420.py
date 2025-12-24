for _ in range(int(input())):
    l=list(map(str,input().split()))
    # print(eval(''.join(l[:-2])))
    # print(l[-1])
    if int(eval(''.join(l[:-2])))==int(l[-1]):
        print("correct")
    else:
        print("wrong answer")