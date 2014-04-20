import random
C = 100
n = 1000
m = 100000
print n, m
for i in xrange(n):
    print random.randint(1, C),
print
for i in xrange(m):
    l = random.randint(1, n)
    r = random.randint(l, n)
    print random.randint(1, C), l, r
