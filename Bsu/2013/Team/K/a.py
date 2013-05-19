n = 23
m = n * (n - 1) / 2

print n, m
for i in xrange(n):
	for j in xrange(n):
		if i < j:
			print i, j