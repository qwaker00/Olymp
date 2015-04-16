import random

n = random.randint(3, 20)
print n
a = set()
for i in xrange(n):
	while True:
		x = random.randint(-20, 20)
		y = random.randint(-20, 20)
		if (x, y) not in a:
			break
	a.add( (x, y) )
	print x, y
