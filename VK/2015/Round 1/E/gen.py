import random

n = random.randint(1, 3000)
m = random.randint(1, 3000)
k = random.randint(1, 200000)
q = random.randint(1, 200000)

print n, m, k, q
l = set()
for i in xrange(k):
	while True:
		x, y = random.randint(1, n), random.randint(1, m)
		if (x, y) not in l:
			break
	l.add( (x, y) )
	print x, y

for i in xrange(q):
	x1 = random.randint(1, n)
	y1 = random.randint(1, m)
	x2 = random.randint(x1, min(x1 + 10, n))
	y2 = random.randint(y1, min(y1 + 10, m))
	print x1, y1, x2, y2


