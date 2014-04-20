

N = 7
s = [[] for i in xrange(100)]
for i in xrange(0, 10 ** N):
	s[len(str(i * i))].append(str(i * i))

for n in xrange(2, N + N + 1, 4):
	for i in s[n / 2]:
		if i == '0': continue
		for k in xrange(n / 2 + 1):
			for j in s[k]:
				s2 = j
				while len(s2) < n / 2: s2 = '0' + s2
				x = int(i + s2)
				l = 0
				r = x / 2
				while l < r:
					c = (l + r + 1) / 2
					if c * c > x:
						r = c - 1
					else:
						l = c
				if l * l == x:
					print '%d: %s %s' %(len(str(x)), i, s2)