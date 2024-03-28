t=int(input())
for i in range(t):
    a,b=map(str,input().split())
    a=float(a)
    if b=="kg":
        print(f"{round(2.2046*a,4):.4f} lb")
    if b=="lb":
        print(f"{round(0.4536*a,4):.4f} kg")
    if b=="l":
        print(f"{round(0.2642*a,4):.4f} g")
    if b=="g":
        print(f"{round(3.7854*a,4):.4f} l")
