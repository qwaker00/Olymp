import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 100
l = 1
for i in xrange(100):
    for j in xrange(12):
        out(random.choice('a'))
    print

    l += 1
    if l == 15:
        l = 1