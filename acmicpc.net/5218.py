for _ in range(int(input())):
    s1,s2=map(str,input().split())
    print("Distances:", end='')
    for j in range(len(s1)):
        k=ord(s2[j])-ord(s1[j])
        if k<0:k+=26
        print(f" {k}", end='')
    print()