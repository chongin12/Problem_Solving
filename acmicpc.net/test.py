fib = [0 for i in range(100)]
fib[1]=1
x = int(input())
for i in range(2,x,1):
    fib[i] = fib[i-1] + fib[i-2]
print(fib[x])