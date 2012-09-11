from random import randint  as rand

print 200
for i in xrange(200):
	s = ''
	for j in xrange(10000):
		s += chr(rand(0, 9) + 48)
	print s
