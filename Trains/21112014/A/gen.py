
a = []

for i in xrange(1, 9):
	for j in xrange(1, 9):
		if i < j:
			a.append((i, j))

for w in a:
	for v in a:
		print w[0], w[1], v[0], v[1]

