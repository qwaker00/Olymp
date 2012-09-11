import string

P = []
for clas in xrange(1, 4):
	ww = {}
	for n in xrange(1, 51):
		f = open('train/%d/%03d.txt' % (clas, n)).readlines()
		words = filter(lambda c: c == ' ' or c in string.letters, ' '.join(f[1:]).lower()).split()
		for w in words:
			ww[w] = ww.get(w, 0) + 1
	P.append(ww)
print str(P).replace(' ', '')

#stoplist = ['the', 'a', 'of', 'in', 'on', 'that', 'an', 'to', 'and', 'from', 'by', 'for', 'us', 'is', 'with', 'at', 'it', 'was', 'its', 'as']
#for w in stoplist:
#	del ww[w]
