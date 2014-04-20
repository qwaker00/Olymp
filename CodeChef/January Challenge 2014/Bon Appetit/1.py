import random
print 3
for it in xrange(3):
	print 10**5, 10**9
	l, r, k = random.randint(0, 10**9), random.randint(0, 10**9), random.randint(1, 2)
	for i in xrange(10**5):
		print l, r, k