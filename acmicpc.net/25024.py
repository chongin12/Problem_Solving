T=int(input())
for _ in range(T):
    x,y=map(int,input().split())
    s=""
    if x<24 and y<60:s+="Yes "
    else:s+="No "
    if x in [1,3,5,7,8,10,12] and y in range(1,32):s+="Yes"
    elif x in [4,6,9,11] and y in range(1,31):s+="Yes"
    elif x == 2 and y in range(1,30):s+="Yes"
    else:s+="No"
    print(s) 