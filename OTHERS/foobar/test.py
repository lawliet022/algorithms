from itertools import combinations
	
def solution(n, m):
	res = [[] for i in range(n)]
	if m == 0:
		return res
	s = 0
	for c in combinations(res,n-m+1):
		for item in c:
			item.append(s)
		s += 1
		print(res)
	return res


print(solution(5,3))
