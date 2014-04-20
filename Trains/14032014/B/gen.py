import random
n = random.randint(1, 20)
k = random.randint(1, 1000)
print n, k
for i in xrange(n):
    print random.randint(1, 1000),
print