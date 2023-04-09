# max flow Edmonds-Karp algorithm from https://cp-algorithms.com/graph/edmonds_karp.html#toc-tgt-2

def bfs(n, source, sink, adj, capacity):
	parent = []
	for i in range(0,n+1):
		parent.append(-1)
	parent[source] = -2
	
	q = []
	q.append([source,10000000000000000])
	while len(q) > 0:
		p = q.pop(0)
		cur = p[0]
		flow = p[1]
		for x in adj[cur]:
			if parent[x] == -1 and capacity[cur][x] > 0:
				parent[x] = cur
				new_flow = min(flow,capacity[cur][x])
				if x == sink:
					return [new_flow,parent]
				else:
					q.append([x,new_flow])
					
	return [0,parent]


def removeDup(a):	# removes dulplicates from list
	b = []
	for i in a:
		if i in b:
			continue
		else:
			b.append(i)
	return b

# returns the max flow possible through given graph
def max_flow(n, source, sink, adj, capacity):
	flow = 0
	new_flow = 0
	flow = 0
	
	while True:
		[new_flow, parent] = bfs(n, source, sink, adj, capacity)
		if new_flow == 0:
			return flow
		flow += new_flow
		cur = sink
		while cur != source:
			prev = parent[cur]
			capacity[prev][cur] -= new_flow
			capacity[cur][prev] += new_flow
			cur = prev
	


def solution(entrances, exits, path):
	if len(exits) == 0 or len(entrances) == 0:
		return 0
	n = len(path)
	
	source = entrances[0]
	sink = exits[0]
	
	for i in range(1,len(entrances)):
		for j in range(0,n):
			path[source][j] += path[entrances[i]][j]
	
	capacity = []
	for i in range(0,n):
		capacity.append([])
		
	for i in range(0,n):
		for j in range(0,n):
			capacity[i].append(0)
	
	adj = []
	for i in range(0,n):
		adj.append([])
	
	for i in range(n):
		if i in entrances:
			if i != source:
				continue
			else:
				for j in range(n):
					if path[source][j] > 0:
						if j in exits:
							adj[source].append(sink)
							capacity[source][sink] += path[source][j]
						else:
							adj[source].append(j)
							capacity[source][j] += path[source][j]
		elif i in exits:
			continue
		else:
			for j in range(0,n):
				if j in entrances:
					continue
				if path[i][j] > 0:
					if j in exits:
						adj[i].append(sink)
						capacity[i][sink] += path[i][j]
					else:
						adj[i].append(j)
						capacity[i][j] += path[i][j]
	for i in range(0,n):
		adj[i] = removeDup(adj[i])

	# print(source,sink)
	# print(adj)
	# print(capacity)
	
	return max_flow(n,source,sink,adj,capacity)
	
print(solution([0,1],[4,5],
				[[0,0,4,6,0,0],
				[0,0,5,2,0,0],
				[0,0,0,0,4,4],
				[0,0,0,0,6,6],
				[0,0,0,0,0,0],
				[0,0,0,0,0,0]
				]))
		
# print(solution([0],[3],[[0,7,0,0],
						# [0,0,6,0],
						# [0,0,0,8],
						# [9,0,0,0]]))
