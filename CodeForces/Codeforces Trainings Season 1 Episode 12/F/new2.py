

N = 7
#xx = sqrt( ((sqrt(10 ** (N - 2)) + 1) ** 2) * (10 ** (N - 1)) )
xx = sqrt( ((sqrt(10 ** (N - 3)) + 1) ** 2) * (10 ** (N - 2)) )
while True:
	i = 1
	x = xx * xx
#	print x
	while True:
		y = x * i * i
		if len(str(y)) == N + N:
#			print y, i
			s = str(y)
			x1 = int(s[:len(s) / 2])
			x2 = int(s[len(s) / 2:])
			sx1 = sqrt(x1)
			if sx1 * sx1 == x1:
				sx2 = sqrt(x2)
				if sx2 * sx2 == x2:
					print 'ANS:', s
					sys.exit(0)
			
		if len(str(y)) > N + N:
			break
		i += 1
	xx += 1
sys.exit(0)
