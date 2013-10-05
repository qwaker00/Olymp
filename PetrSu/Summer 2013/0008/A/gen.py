import random

for i in xrange(2000):
	n = 50
	r = 10**9
	print n, r
	for j in xrange(n):
		print random.randint(-10**9, 10**9), random.randint(-10**9, 10**9)

print 0, 0