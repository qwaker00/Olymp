import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 100, 500
for i in xrange(100):
    print random.uniform(0, 1),
print
for i in xrange(100):
    print 1,
print