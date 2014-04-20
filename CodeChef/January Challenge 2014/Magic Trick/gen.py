import random

print 100
for it in xrange(100):
	print 1000
	for i in xrange(1000):
		print random.randint(0, 10**18), 
	print
	print random.randint(0, 10**18), random.randint(0, 10**18), random.randint(0, 10**18)
	print ''.join([random.choice('ARM') for i in xrange(1000)])