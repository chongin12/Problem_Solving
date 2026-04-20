t=int(input())
for i in range(t):
    n=int(input())%25
    if n>=17 and n<25:print("OFFLINE")
    else:print("ONLINE")