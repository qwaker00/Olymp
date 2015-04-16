import random, string, sys


n = 300000
m = 100000
l = 50

alf = string.letters + "&-'" + string.digits
st = []
ss = set()
for i in xrange(n):
	s = ''
	for j in xrange(l):
		s += random.choice(alf)
	st.append(s)
	assert s not in ss
	ss.add(s)

print >>sys.stderr, 'here'

li = []
ss = set()
for i in xrange(m):
	s = ''
	for j in xrange(l):
		s += random.choice(alf)
	li.append(s)
	assert s not in ss
	ss.add(s)

print 1
print 
print 'Stops:', ', '.join(st)
print 'Lines:', ', '.join(li)
for i, l in enumerate(li):

	sta = []
	for j in xrange(3 * i, 3 * i + 4):
		if j < len(st):
			sta.append(st[j])

	print l, 'route:', ', '.join(sta)


print 'Jo li at', st[0]
print 'Mi li at', st[-1]



	
