from functools import cmp_to_key

def comp(x, y):
    a = x.split('.')    #spliting on '.'
    b = y.split('.')
    n = min(len(a),len(b)) 
    
    for i in range(n):
        if int(a[i]) < int(b[i]):
            return -1
        elif int(a[i]) > int(b[i]):
            return 1

    if len(a) < len(b):     # comparison on length
        return -1
    return 1

def solution(l):
    
    #sorting using a comparator function
    l = sorted(l, key = cmp_to_key(comp))
    return l

print(solution(["1.11","2.0.0","1.2","2","0.1","1.2.1","1.1.1","2.0"]))
print(solution(["1.1.2","1.0","1.3.3","1.0.12","1.0.2"]))
