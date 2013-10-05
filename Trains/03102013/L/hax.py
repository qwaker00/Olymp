import sys, os, random, string

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

print 25
for i in xrange(25):
    print 10**6
    print ''.join(random.choice(string.letters[:26]) for i in xrange(10**6))
    s = list(string.letters[:26])
    random.shuffle(s)
    print ''.join(s)