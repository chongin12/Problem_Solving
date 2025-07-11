s=input()
n=int(input())
arr=[]
for i in range(n):
    arr.append(input())

for i in range(26):
    newS=""
    for ch in s:
        newS+=chr((ord(ch)-97+i)%26+97)
    for k in arr:
        if k in newS:
            print(newS)
            exit(0)