import sys, os, random, string

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 50000, 6
for i in xrange(50000):
    a = []
    for j in xrange(6):
        a.append(random.choice(string.letters[:26]))
    print ''.join(a)