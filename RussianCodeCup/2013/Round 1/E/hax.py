import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 150
for i in xrange(150):
    print rand(-20000, 20000), rand(-20000, 20000)