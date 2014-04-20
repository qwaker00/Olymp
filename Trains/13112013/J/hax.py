import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 5000
for i in xrange(5000):
    print 0, i, 1
print sum(xrange(5000))