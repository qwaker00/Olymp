import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 10**5, 10**5
for i in xrange(10**5):
    print rand(0, 10**9),
print
for i in xrange(10**5):
    print rand(0, 10**9),
print

n = 10**5
for i in xrange(10**5 - 1):
    l = rand(1, n)
    r = rand(1, n)
    c = rand(1, min(n - l + 1, n - r + 1))
    print 1, l, r, c
print 2, 1
print
