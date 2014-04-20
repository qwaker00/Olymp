

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

N = 3
x = 10 ** (N + N + 1) - 1
y = 4

while y < x:
	y *= 4
	z = sqrt(x / y)
	s = str(z * z)
	if len(s) % 2 != N + N: continue
	x1 = int(s[:len(s) / 2])
	x2 = int(s[len(s) / 2:])
	sx1 = sqrt(x1)
	if sx1 * sx1 != x1: continue
	sx2 = sqrt(x2)
	if sx2 * sx2 != x2: continue
	print s