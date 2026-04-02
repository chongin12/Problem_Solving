n=int(input())
for i in range(n):
    a=input()
    r=a.count('a')+a.count('e')+a.count('i')+a.count('o')+a.count('u')
    print(f"The number of vowels in {a} is {r}.")