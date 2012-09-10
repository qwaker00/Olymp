import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 1000000000
print 100000
for i in xrange(100000):
	print i * 2 + 500000000,
print
print 100000
for i in xrange(100000):
	print 500000000 - i * 2 - 1,
print