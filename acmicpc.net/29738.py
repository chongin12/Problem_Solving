T=int(input())
for i in range(T):
    n=int(input())
    s=''
    if n<=25:s='World Finals'
    elif n<=1000:s='Round 3'
    elif n<=4500:s='Round 2'
    else:s='Round 1'
    print(f"Case #{i+1}: {s}")