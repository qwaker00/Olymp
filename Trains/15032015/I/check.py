n, m = map(int, open('.in').readline().split())
a = list(reversed( map(int, open('.out').readline().split()) ))

assert m == len(a)
s = 0
for j, i in zip(range(1, len(a) + 1), a):
	if i < j:
		continue

	C = 1
	for jj in xrange(j, i):
		C = C * (jj + 1) / (jj - j + 1)
	s += C

assert n == s		