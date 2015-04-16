import random

print 1
n = random.randint(1, 100)

a = set()
for i in xrange(n):
	a.add((random.randint(-100, 100), random.randint(-100, 100)))

print len(a)
for b in a:
	print b[0], b[1]
