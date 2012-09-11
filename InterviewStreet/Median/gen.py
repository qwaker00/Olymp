import random

f = open('.rout', 'w')

s = []
print 50000
for i in xrange(50000):
	if (i / 10000) & 2 == 0:
		t = random.randint(-2**31, 2**31 - 1)
		s.append(t)
		print 'a %d' % t
	else:
		t = s[0]
		del s[0]
		print 'r %d' % t

	s.sort()
	if len(s) == 0:
		f.write('Wrong!\n')
	else:
		if len(s) % 2 == 0:
			med = (s[len(s) / 2] + s[(len(s) / 2) - 1]) / 2.
		else:
			med = s[len(s) / 2]
		if int(med) == med: med = int(med)
		f.write(str(med) + '\n')

f.close()
