import random, string
print 10000, 10000, 10000, 10000
s = []
for i in xrange(3000):
    s.append(random.choice(string.letters[26:]))
print ''.join(s)
s = []
for i in xrange(3000):
    s.append(random.choice(string.letters[26:]))
print ''.join(s)

