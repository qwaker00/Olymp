import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

a = []
a.append('0.')
for i in xrange(200):
    a.append(random.choice('0123456789'[0]))
c = a[1:]
for i in xrange(1000000 / 200 - 1):
    a.extend(c)
print ''.join(a)