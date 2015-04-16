for i in xrange(1,7):
	for j in xrange(1,7):
		if (i * j) % 6 == 0 and i <= j:
			print i, j