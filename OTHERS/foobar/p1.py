def solution(i):
	# together all primes till 25000 have more than 12000 digits in total
	# sieve to generate primes till 25000
	prime = [1]*25002
	prime[0] = prime[1] = 0
	for x in range(2,25000):
		if prime[x] == 1:
			for y in range(x*x,25000,x):
				prime[y] = 0
	prime_string = ""
	new_id = ""
	for no in range(2,25000):
		if prime[no] == 1:
			prime_string = prime_string + str(no)
		if len(prime_string) > i + 10:
			break
	new_id = prime_string[i:i+5]
	
	return new_id

print(solution(0))
