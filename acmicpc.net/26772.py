l=[
    " @@@   @@@  ",
    "@   @ @   @ ",
    "@    @    @ ",
    "@         @ ",
    " @       @  ",
    "  @     @   ",
    "   @   @    ",
    "    @ @     ",
    "     @      ",
]
n=int(input())
for k in l:  
    for i in range(n):
        print(k, end='')
    print()