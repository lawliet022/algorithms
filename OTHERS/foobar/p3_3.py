def solution(n):
	steps = 0
	n = int(n)
	
	if n == 0:
	    return 1
	
	while n != 1:
		if n == 3:
			steps += 2
			break
		if n % 2 == 0:
			n = int(n / 2)
		else:
			p = n + 1
			q = n - 1
			cnt1 = 0
			cnt2 = 0
			while p % 2 == 0:
				p = int(p / 2)
				cnt1 += 1
			while q % 2 == 0:
				q = int(q / 2)
				cnt2 += 1
			if cnt1 > cnt2:
				n = n + 1
			else:
				n = n - 1
		steps += 1
	
	return steps

print(solution('15'))
print(solution('4'))
