a=int(input())
res1=0
res2=0
res3=0
if a>=300:
	res1+=a//300
	a=a%300
if a>=60:
	res2+=a//60
	a=a%60
if a>=10:
	res3+=a//10
	a=a%10
if a>0:
	print("-1")
else:
	print(res1,res2,res3)