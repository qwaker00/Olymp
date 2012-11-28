import sys, os, random, string

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 10000, 100000, 26
for i in xrange(10000):
    print 2, 'a b'
for i in xrange(100000):
    print rand(1, 10000),  rand(1, 10000)
print 'E(aU(AGb))'