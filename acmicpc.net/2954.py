n=input()
p1,p2='#','#'
l=['a','e','i','o','u']
r=''
for i in n:
    if i in l and p2 == i and p1 == 'p':
        r=r[:-1]
        p1,p2='#','#'
    else:
        r+=i
        p2=p1
        p1=i
print(r)