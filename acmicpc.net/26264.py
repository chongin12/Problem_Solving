n=int(input())
s=input()
if s.count('s')>s.count('b'):
    print('security!')
elif s.count('s')<s.count('b'):
    print('bigdata?')
else:
    print('bigdata? security!')