import sys, os, random, string

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 500
aa = []
for i in xrange(500):
    a = []
    for j in xrange(5000):
        a.append(random.choice(string.letters))
    print ''.join(a)
    aa.append(a)

print 100
for i in xrange(100):
    a = []
    for j in xrange(10):
        a.extend(random.choice(aa))
    print ''.join(a)

