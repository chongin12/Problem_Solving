a=input()
if len(a)>=3 and a[0]=='"' and a[-1]=='"':
    print(a[1:-1])
else:print("CE")