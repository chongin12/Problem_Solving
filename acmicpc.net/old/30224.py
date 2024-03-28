a=input()
if a.__contains__('7'):
    if int(a)%7==0:print(3)
    else:print(2)
else:
    if int(a)%7==0:print(1)
    else:print(0)