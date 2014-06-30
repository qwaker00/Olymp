import random
print 10
for t in xrange(10):
    print 10000, 15000
    for i in xrange(10000):
        print random.randint(-10**9, 10**9),
    print
    for i in xrange(15000):
        print random.randint(10**17, 10**18),
    print