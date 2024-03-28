a,d,k=map(int,input().split())
print(f"{'X' if (k-a+d)%d!=0 or (k-a+d)//d<=0 else (k-a+d)//d}")