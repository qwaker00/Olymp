import random

n = random.randint(3, 300)
print n
a = set()
for i in xrange(n):
	while True:
		x = random.randint(-10, 10)
		y = random.randint(-10, 10)
		if (x, y) not in a:
			break
	a.add( (x, y) )
	print x, y
