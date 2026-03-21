n=int(input())
a=input()
b=input()
if n%2==1:
    if str(int(a)+int(b)).count('1')==len(a):
        print("Deletion succeeded")
    else:print("Deletion failed")
else:
    if a==b:
        print("Deletion succeeded")
    else:print("Deletion failed")