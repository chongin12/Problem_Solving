for i in range(int(input())):
	a,b,c=map(int,input().split())
	print(f"Case #{i+1}: ",end='')
	if a+b+c<=max(a,b,c)*2:
		print("invalid!")
	elif a==b and b==c:
		print("equilateral")
	elif a==b or b==c or c==a:
		print("isosceles")
	else:
		print("scalene")