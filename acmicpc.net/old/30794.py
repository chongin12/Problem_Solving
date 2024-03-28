a,b=map(str,input().split())
r=int(a)
if b=="miss":r=0
if b=="bad":r*=200
if b=="cool":r*=400
if b=="great":r*=600
if b=="perfect":r*=1000
print(r)