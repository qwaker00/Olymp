import sys

def sqrt(x):
	l = 0
	r = x
	while l < r:
		c = (l + r + 1) / 2
		if c * c > x:
			r = c - 1
		else:
			l = c
	return l

def decomp(n):
	i = 2
	a = []
	while i * i <= n:
		if n % i == 0:
			a.append(i)
			n /= i
		else:
			i += 1
	if n > 1:
		a.append(n)
	return '*'.join(map(str, a))

N = 10
i = 0
fin = 10 ** N
lastl = -1
while i < fin:
	i += 1

	x = i * i
	l = len(str(x))

#	print 'i:', i
#	if l % 2 == 0: continue

	xx = sqrt(x * (10 ** l))
	for it in xrange(3):
		s = str( (xx + it) * (xx + it) )

		if len(s) % 2 != 0: continue
		x1 = int(s[:len(s) / 2])
		x2 = int(s[len(s) / 2:])

		sx1 = sqrt(x1)
		if sx1 * sx1 != x1: continue
		sx2 = sqrt(x2)
		if sx2 * sx2 != x2: continue

#		ans.append(s)

#		if s[len(s) / 2:][0] != '9': continue

#		if len(s) != lastl and len(s) % 4 != 0:
		print '%s: %s %s : %s' % (len(s), s[:len(s) / 2], s[len(s) / 2:], decomp(int(s)))
#		lastl = len(s)

#		print i, sqrt(10 ** (len(s) / 2)) - 1
#		i = max(i, sqrt(10 ** (len(s) / 2)) - 1)
#		break
#		print '%s%s %s %s' % (' '*(len(str(len(s))) + 2), sqrt(int(s[:len(s) / 2])), sqrt(int(s[len(s) / 2:])), xx + it)