l=[
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you",
    "Never gonna stop"
]
n=int(input())
k="No"
for _ in range(n):
    a=input()
    if l.__contains__(a) == False:
        k="Yes"
        break
print(k)