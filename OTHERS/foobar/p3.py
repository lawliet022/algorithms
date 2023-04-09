def xorTill(n):
    if n <= 0:
        return 0
    if int((n+1)/2)&1:
        ans = 1
    else:
        ans = 0
    n += 1
    for i in range(1,32):
        p = n % (1<<(i+1))
        p -= (1<<i)
        if p > 0 and (p&1):
            ans = ans | (1<<i)
    
    return ans

def xorRange(l, r):
    return (xorTill(r) ^ xorTill(l-1))

def solution(start, length):
    line = 0
    canTake = length
    ans = 0
    
    while canTake > 0:
        l = start + line * length
        r = l + canTake - 1
        ans = ans ^ xorRange(l,r)
        print(l,r,xorRange(l,r))
        canTake -= 1
        line += 1
    
    return ans

print(solution(0,3))
print(xorTill(2))
