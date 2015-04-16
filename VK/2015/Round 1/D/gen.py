import random
n = 20000
M = random.randint(1, 20000)
T = random.randint(1, 86400)
a = []
for i in xrange(20000):
	a.append(random.randint(0, 86400 - T))
print n, M, T
for x in sorted(a):
	print '%02d:%02d:%02d' % (x / 3600, (x / 60) % 60, x % 60)

