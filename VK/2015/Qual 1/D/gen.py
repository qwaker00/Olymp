import random
n = random.randint(1, 10000)
m = min(n * (n + 1) / 2, 100000)
print n, m
for i in xrange(n):
	print random.randint(-10**9, 10**9),
print

"""
out = 0
for i in xrange(n):
	if out == m: break
	for j in xrange(i, n):
		if out == m: break
		out += 1
		print i + 1, j + 1
"""
for i in xrange(m):
	x = random.randint(1, n)
	y = random.randint(x, n)
	print x, y