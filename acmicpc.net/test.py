G=[[] for i in range(1001)]

def longestStrChain(words):
    res=0
    words.sort(key=lambda x : len(x))
    print(words)
    for i in range(len(words)):
        for j in range(i+1, len(words)):
            if len(words[i])==len(words[j]):continue
            elif len(words[i])+1<len(words[j]):break
            shift=0
            for k in range(len(words[i])):
                if words[i][k]!=words[j][k+shift]:
                    shift+=1
                    if shift>=2:break
                    if words[i][k]!=words[j][k+shift]:
                        shift=2
                        break
            if shift<=1:
                G[i].append(j)
                print(f"G[{i}].append({j})")
    for i in range(len(words)):
        res=max(res,dfs(i))
    return res

def dfs(x):
    ret=0
    for i in G[x]:
        ret=max(ret,dfs(i))
    return ret+1

print(longestStrChain(["xbc","pcxbcf","xb","cxbc","pcxbc"]))