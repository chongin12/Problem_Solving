t=int(input())
for _ in range(t):
    input()
    c,y,su,sa,f=map(int,input().split())
    b,gs,gc,w=map(int,input().split())
    p=int(16*min(c/8,y/8,su/4,sa,f/9))
    print(min(p,b+gs//30+gc//25+w//10))