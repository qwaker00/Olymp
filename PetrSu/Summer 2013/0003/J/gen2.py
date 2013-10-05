import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

n = 200000
print n
for i in xrange(n- 1):
    print i + 1, i + 2