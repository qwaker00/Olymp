import random
n = 3 * 10**5
print n, 1, n - 1
for i in xrange(n - 1):
    print i + 2, random.randint(1, i + 1)