p = 299993
x0 = 1

print 3 * (10**5)
for i in xrange(50):
	x1 = (x0 + x0) % p
	if x1 > x0:
		print '>'
	elif x1 == x0:
		print '='
	else:
		print '<'
	x0 = x1 