T=int(input())
for _ in range(T):
    N=int(input())
    if (N+1)%(N%100)==0:print("Good")
    else:print("Bye")