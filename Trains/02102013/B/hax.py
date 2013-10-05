import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 100000
print '0 ' * 99999 + ' 100000000'
for i in xrange(99999):
    print i + 1, i + 2