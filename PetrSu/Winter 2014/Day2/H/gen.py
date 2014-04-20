import random, string
print ''.join(random.choice(string.letters[:26]) for i in xrange(2000))
print 1