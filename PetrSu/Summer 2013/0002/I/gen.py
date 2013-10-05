from random import randint

n = 1000
q = 500000

print n, q

for i in xrange(2, n + 1):
	print i - 1, i, randint(1, 100000)
print

cq = 500
for i in xrange(cq):
	print 1, 1, n, randint(1, 10**5)

for i in xrange(cq, q):
	print 2, 1, n






