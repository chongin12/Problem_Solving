a=input()
b=input()
c=input()
r=0
if a!="FizzBuzz" and a!="Fizz" and a!="Buzz":
    r=int(a)+3
elif b!="FizzBuzz" and b!="Fizz" and b!="Buzz":
    r=int(b)+2
else:r=int(c)+1

if r%3==0 and r%5==0:
    print("FizzBuzz")
elif r%3==0:
    print("Fizz")
elif r%5==0:
    print("Buzz")
else:print(r)