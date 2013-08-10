import random

print 10
for t in xrange(10):
    print 250, 250, 2
    for i in xrange(250):
        print random.randint(0, 10), 1
    for i in xrange(250):
        print random.randint(0, 1000000000), random.randint(1, 1000000)
