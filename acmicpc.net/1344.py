a=float(input())/100
b=float(input())/100

l=[0,1,4,6,8,9,10,12,14,15,16,18]
fact=[1]
for i in range(18):
    fact.append(fact[-1]*(i+1))
r=0.0
for i in l:
    aGoal=fact[18]/fact[i]/fact[18-i]*(a**i)*((1-a)**(18-i))
    for j in l:
        bGoal=fact[18]/fact[j]/fact[18-j]*(b**j)*((1-b)**(18-j))
        r+=aGoal*bGoal
print(f"{1-r:.7f}")
