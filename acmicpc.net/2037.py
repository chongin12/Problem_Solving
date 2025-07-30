d={
    "A": 21,
    "B": 22,
    "C": 23,
    "D": 31,
    "E": 32,
    "F": 33,
    "G": 41,
    "H": 42,
    "I": 43,
    "J": 51,
    "K": 52,
    "L": 53,
    "M": 61,
    "N": 62,
    "O": 63,
    "P": 71,
    "Q": 72,
    "R": 73,
    "S": 74,
    "T": 81,
    "U": 82,
    "V": 83,
    "W": 91,
    "X": 92,
    "Y": 93,
    "Z": 94,
    " ": 1,
}

p,w=map(int,input().split())
s=input()
r=d[s[0]]%10*p
for i in range(1,len(s)):
    if s[i]==' ':
        r+=p
        continue
    if d[s[i-1]]//10==d[s[i]]//10:r+=w
    r+=d[s[i]]%10*p
print(r)