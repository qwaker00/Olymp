import random
print 5000, 20
for i in xrange(5000):
	print random.randint(1, 10**7 / 2) * 2,
print
print 20
for i in xrange(20):
	print random.randint(1, 10**8) * 2 - 1
