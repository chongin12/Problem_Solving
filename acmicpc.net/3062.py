t=int(input())
def isPalindrome(word):
    for i in range(0, int(len(word)/2)):
        if word[i] != word[len(word)-1 - i]:
            return "NO"
    return "YES"
for i in range(t):
    n=input()
    print(isPalindrome(str(int(n)+int(n[::-1]))))