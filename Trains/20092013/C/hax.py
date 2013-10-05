import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 2000
for i in xrange(2000):
    print random.randint(1, 10**9), 
print