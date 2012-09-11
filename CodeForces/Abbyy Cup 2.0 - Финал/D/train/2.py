import string

def Hash(s):
	s = ''.join(filter(lambda x: x in string.letters, s)).lower()
	h = 0
	for c in s:
		h = (h * 257 + ord(c)) % 2**128
	return h

stat = [{}, {}, {}]
for fold in xrange(1, 4):
	totwrd = 0
	for i in xrange(1, 51):
		fn = '%03d.txt' % i
		t = open('%d/' % fold + fn).readlines()
		text = '\n'.join(t[1:])
		text =  ''.join(filter(lambda x: x in string.letters or x == ' ' or x == '\n', text)).lower()
		text = text.replace('\n', ' ')
		wrd = filter(lambda x: x != '', text.split())
		totwrd += len(wrd)
		for word in wrd:
			stat[fold - 1][word] = stat[fold - 1].get(word, 0) + 1
#	for w in stat[fold - 1].keys():
#		stat[fold - 1][w] = float(stat[fold - 1][w]) / totwrd

print stat
