import random
print 100000
for i in xrange(10**5):
	print random.randint(10**9, 10**9),
print
for i in xrange(10**5):
	l = random.randint(1, 1)
	r = l + random.randint(10**5 - l, 10**5 - l)
	print l, r
print 1
print 2, 1, 10**5

