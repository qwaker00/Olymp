import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

for i in xrange(20):
    print 20, i + 1
    print ' '.join([str(rand(0, 50)) for i in xrange(20)])