n=int(input())
v=[]
for i in range(n):
    b,a=map(str,input().split())
    v.append((-int(a),b))
v.sort()
print(v[0][1])