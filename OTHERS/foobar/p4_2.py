def solution(num_buns, num_required):
	length = num_buns - num_required + 1
	
	answer = []                 # initialise empty
	for i in range(num_buns):
		answer.append([])
		
	combinations = []                   
	for mask in range((1<<num_buns)):       # generate all combinations of len = length
		submask = []
		for j in range(0,num_buns):
			if (mask&(1<<j)):
				submask.append(j)
		if len(submask) == length:
			combinations.append(submask)
	combinations.sort()                     # sort to get least lexicographical order
	val = 0
	for i in range(len(combinations)):
		for x in combinations[i]:
			answer[x].append(val)
		val += 1
		
	return answer

print(solution(5,3))
print(solution(4,1))
