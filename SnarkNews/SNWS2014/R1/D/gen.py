import random

print 50
for T in xrange(50):
	p = genprime(30000)
	q = genprime(30000)
	n = p * q
	m = random.randint(0, n - 1)
	