import random, sys

print 1
for it in xrange(1):
	n = random.randint(40, 40)
	a = range(1, n + 1)
	random.shuffle(a)

	print n
	for i in xrange(1, n + 1):
		b = []
		for x in a:
			if x < i:
				b.append(x)
			elif x > i:
				b.append(x - 1)
		print ' '.join('%3d' % x for x in b)

	print >>sys.stderr, ' '.join('%3d' % x for x in a)