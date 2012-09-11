import string

def Hash(s):
	s = ''.join(filter(lambda x: x in string.letters, s)).lower()
	h = 0
	for c in s:
		h = (h * 257 + ord(c)) % 2**128
	return h


hh = {}
for fold in xrange(1, 4):
	print '{'
	for i in xrange(1, 51):
		fn = '%03d.txt' % i
		t = open('%d/' % fold + fn).readlines()
		text = '\n'.join(t[1:])
		print '{"%s", %d},' % (t[1].strip(), h)

		if h in hh.keys() and hh[h] != fold:
			print 'ERRROR'
			import sys
			sys.exit(0)
		hh[h] = fold

	print '},'
