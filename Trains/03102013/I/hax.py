import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

d = {}

n = 132

print 100
for it in xrange(1000):
    print n
    for i in xrange(n):
        r = rand(1, 100000)
        while r in d:
            r = rand(1, 100000)
        d[r] = 1

        dd = (random.randint(2000, 3000), random.randint(1, 12), random.randint(1, 30))
        while dd in d:
            dd = (random.randint(2000, 3000), random.randint(1, 12), random.randint(1, 30))
        d[dd] = 1

        print '%s %s' % ('%s/%s/%s' % dd, r)