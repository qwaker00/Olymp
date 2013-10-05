import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

n = 200000
print n - 1
for i in xrange(n / 2 - 1):
    print i * 2 + 1, i * 2 + 2
    print i * 2 + 1, i * 2 + 3