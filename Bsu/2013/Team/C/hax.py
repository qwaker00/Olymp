import sys, random, string

print 60
for i in xrange(60):
	print ''.join(random.choice(string.letters[:26]) for j in xrange(10000))
