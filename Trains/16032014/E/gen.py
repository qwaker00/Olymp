import random, sys, string

n = random.randint(1, 10000)
for i in xrange(n):
    sys.stdout.write(random.choice(string.letters[:2] * 5 + '?'))
print
