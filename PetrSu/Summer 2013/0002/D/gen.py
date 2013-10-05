from random import randint

n = 50000
k = 50
c = 50

print n, k, c

for i in xrange(n):
	print randint(1, c),
print

for i in xrange(1, n):
	print i, i + 1

q = 100000
print q

for i in xrange(q):
	d = randint(1, 2)
	print d,
	if d == 1:
		print randint(1, n), randint(1, c)
	else:
		print randint(1, n), randint(1, k)






