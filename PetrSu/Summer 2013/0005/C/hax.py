import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

n = 20000
m = 20000
e = []
w = [rand(-10000, 10000) for i in xrange(n)]
ids = range(1, n + 1)
random.shuffle(ids)
for i in xrange(2, n + 1):
    e.append( (rand(1, i - 1), i) )
for i in xrange(len(e)):
    if rand(0, 1) == 0:
        e[i] = (ids[e[i][1] - 1], ids[e[i][0] - 1])
    else:
        e[i] = (ids[e[i][0] - 1], ids[e[i][1] - 1])
random.shuffle(e)

print n, m
print ' '.join(map(str, w))
for ee in e:
    print '%d %d' % ee

for i in xrange(m):
    if rand(0, 1) == 0:
        print 1, rand(1, n), rand(1, n), rand(-10000, 10000)
    else:
        print 2, rand(1, n), rand(1, n), 0