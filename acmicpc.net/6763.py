a=int(input())
b=int(input())
b-=a
c="You are speeding and your fine is $"
if b<1:print("Congratulations, you are within the speed limit!")
elif b<21:print(c+"100.")
elif b<31:print(c+"270.")
else:print(c+"500.")