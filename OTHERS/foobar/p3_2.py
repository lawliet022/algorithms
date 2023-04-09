def gcd(a,b):       # return gcd of number a and b
    while b > 0:
        a %= b
        t = a
        a = b
        b = t
    return a

def getSubMatrix(m, x, y):      # returns a submatrix not containing row x and col y
    mat = []
    for i in range(0,len(m)):
        temp = []
        for j in range(0,len(m[i])):
            if i == x or j == y:
                continue
            temp.append(m[i][j])
        if len(temp) > 0:
            mat.append(temp)
    
    return mat
    
def getDeterminant(mat):    # returns determinant of matrix
    if len(mat) == 2:
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]
    else:
        det = 0
        for i in range(0,len(mat)):
            sub_matrix = getSubMatrix(mat,0,i)
            det += ((-1)**i) * mat[0][i] * getDeterminant(sub_matrix)
        return det

def getInverse(Qx):     # returns inverse of a matrix
	if len(Qx) == 2:
		inv = [[Qx[1][1],-Qx[0][1]],[-Qx[1][0],Qx[0][0]]]
		return inv
		
	minors = []
	for i in range(len(Qx)):
		minors.append([])
	for i in range(len(Qx)):
		for j in range(len(Qx)):
			minors[i].append(getDeterminant(getSubMatrix(Qx,i,j)))
			

	# adjoint matrix (by transponse and sign change of minors)
	adj = []
	for i in range(len(Qx)):
		adj.append([])
	for i in range(len(Qx)):
		for j in range(len(Qx)):
			adj[i].append(0)
	for i in range(len(Qx)):
		for j in range(len(Qx)):
			adj[i][j] = (-1)**(i+j) * minors[j][i];
	
	return adj

	

def matrixMultiply(Qx , Rx):    # return a new matrix M = Qx * Rx
	if len(Qx[0]) != len(Rx):
		raise Exception("Invalid Matrix multiplication")
	
	c = len(Rx)
	ans = []
	for i in range(len(Qx)):
		ans.append([])
	for i in range(len(Qx)):
		for j in range(len(Rx[0])):
			val = 0
			for k in range(0,c):
				val += Qx[i][k] * Rx[k][j]
			ans[i].append(val)
	return ans

def updateMatrix(m):
	cnt = 0
	p = []
	for i in range(12):
		p.append(-1)
	for i in range(len(m)):
		flag = 0
		for j in range(len(m)):
			if m[i][j] != 0:
				flag = 1
		if flag == 1:
			p[i] = cnt
			cnt += 1
	
	for i in range(0,len(m)):
		if(p[i] == -1):
			p[i] = cnt
			cnt += 1

	mat = []
	for i in range(0,len(m)):
		mat.append([])

	for i in range(0,len(m)):
		for j in range(0,len(m)):
			mat[i].append(0)
	
	for i in range(0,len(m)):
		for j in range(0,len(m)):
			mat[p[i]][p[j]] = m[i][j]
	
	return mat
	
def solution(m):
	
	m = updateMatrix(m)
		
	n = len(m)
	k = -1
	for i in range(0,n):
		current_sum = 0
		for j in range(0,n):
			current_sum += m[i][j]
		if current_sum > 0:
			k = i
	if k == -1:
		return [1,1]
	# handle k = 0 case seperately
	det = 0
	if k > 0:
		Qx = []
		Qy = []
		for	i in range(0,k+1):
			x = []
			y = []
			row_sum = 0
			for j in range(0,n):
				row_sum += m[i][j]
			for j in range(0,k+1):
				x.append(m[i][j])
				y.append(row_sum)
			Qx.append(x)
			Qy.append(y)
		
		Rx = []
		Ry = []
		for	i in range(0,k+1):
			x = []
			y = []
			row_sum = 0
			for j in range(0,n):
				row_sum += m[i][j]
			for j in range(k+1,n):
				x.append(m[i][j])
				y.append(row_sum)
			Rx.append(x)
			Ry.append(y)
		
			
		# normalise matrix
		lcm = 1
		for x in Qy:
			for y in x:
				lcm = (lcm * y) // gcd(lcm,y)
				
		for x in range(0,len(Qx)):
			for y in range(0,len(Qx[x])):
				Qx[x][y] = Qx[x][y] * lcm // Qy[x][y]
				
		for x in range(0,len(Rx)):
			for y in range(0,len(Rx[x])):
				Rx[x][y] = Rx[x][y] * lcm // Ry[x][y]
		
		
		# (I - Q)
		for i in range(len(Qx)):
			for j in range(len(Qx)):
				if i == j:
					Qx[i][i] = lcm - Qx[i][i]
				else:
					Qx[i][j] = -Qx[i][j]
			det = getDeterminant(Qx)

	X = [[]]
	if det == 0 or k == 0:
		val = 0
		for i in range(len(m[0])):
			val += m[0][i]
		for i in range(k+1,len(m[0])):
			X[0].append(m[0][i])
		denominator = val
		
	else:	
		inv = getInverse(Qx)
		X = matrixMultiply(inv,Rx)
		denominator = det
	
	num_gcd = X[0][0]
	for i in range(1,len(X[0])):
		num_gcd = gcd(num_gcd,X[0][i])
	
	res_gcd = gcd(num_gcd,denominator)
	
	answer = []
	for x in range(len(X[0])):
		answer.append(long(X[0][x]//res_gcd))
	answer.append(long(denominator//res_gcd))
	
	return answer

size = int(input())
m = []
for i in range(size):
	m.append([])
for i in range(size):
	for j in range(size):
		m[i].append(0)
for i in range(size):
	for j in range(size):
		m[i][j] = int(input())
print(solution(m))
# print(solution([[8,5,1,8,4,7,5,7],
				# [0,0,0,0,0,0,0,0],
				# [0,0,0,0,0,0,0,0],
				# [0,0,6,3,3,6,2,2],
				# [1,6,2,7,3,7,7,7],
				# [0,0,0,0,0,0,0,0],
				# [0,0,0,0,0,0,0,0],
				# [0,0,0,0,0,0,0,0]]))
# print(solution([[0,1,0,0,0,1],[4,0,0,3,2,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]))
# print(solution([[0,2,1,0,0],[0,0,0,3,4],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]))
