import random

print 300, 300
for i in xrange(300):
    for j in xrange(300):
        print random.randint(-100, 100),
    print

print 100
for i in xrange(100):
    print 299 - i * 3, 299 - i * 3
