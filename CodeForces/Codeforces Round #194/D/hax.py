import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 1000, 1000
for i in xrange(1000):
    for j in xrange(1000):
        print rand(0, 10**9),
    print