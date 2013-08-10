import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 100
for t in xrange(100):
    print 100
    for i in xrange(100):
        print rand(0, 100),
    print
    for i in xrange(100):
        print rand(0, 100),
    print
