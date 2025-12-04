cnt=0
while True:
    cnt+=1
    a=input()
    if a.split()[1]=="E":break
    print(f"Case {cnt}: {str(eval(a)).lower()}")