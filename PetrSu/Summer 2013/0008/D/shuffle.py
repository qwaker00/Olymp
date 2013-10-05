import sys, random

for s in sys.stdin:
	s = s.rstrip('\n')
	ss = list(s)
	random.shuffle(ss)
	print (''.join(ss))

	ss = list(s)
	a = []
	l = len(ss)
	for i in range(l // 4):
		p = ss[i * 4: i * 4 + 4]
		random.shuffle(p)
		a.extend(p)

	for i in range(l // 10):
		i = random.randint(0, len(a) - 1)
		j = random.randint(0, len(a) - 1)
		t = a[i]
		a[i] = a[j]
		a[j] = t
	print (''.join(a))