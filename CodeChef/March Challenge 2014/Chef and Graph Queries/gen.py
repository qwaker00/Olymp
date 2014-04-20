import random
n = 1000
m = 100000
q = n * (n + 1) / 2
print 3
for T in xrange(3):
    print n, m, q
    for i in xrange(m):
        print random.randint(1, n), random.randint(1, n)
    for i in xrange(1, n + 1):
        for j in xrange(i, n + 1):
            print i, j


