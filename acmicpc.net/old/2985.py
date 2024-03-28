a,b,c=map(int,input().split())
d=""
e="="
if a+b==c:
	d="+"
elif a-b==c:
	d="-"
elif a*b==c:
	d="*"
elif a//b==c:
	d="/"
elif a==b+c:
	d="="
	e="+"
elif a==b-c:
	d="="
	e="-"
elif a==b*c:
	d="="
	e="*"
elif a==b//c:
	d="="
	e="/"
print(f"{a}{d}{b}{e}{c}")