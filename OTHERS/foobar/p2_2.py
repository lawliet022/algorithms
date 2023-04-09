def getParent(cur, level, isRight, n):
    total = (1<<level) - 1
    if cur == total:
        if isRight == 1:
            return n + 1
        else:
            return n + (1<<level)
    if cur <= int(total/2):
        return getParent(cur,level-1,0,n)
    else:
        return getParent(cur-int(total/2),level-1,1,n)

def solution(h, q):
    ans = []
    for query in q:
        if query == ((1<<h)-1):
            ans.append(-1)
        else:
            ans.append(getParent(query,h,0,query))
    return ans

print(solution(5,[19,14,28]))
print(solution(3,[7,3,5,1]))
