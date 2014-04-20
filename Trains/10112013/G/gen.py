from random import randint

n = 20000
s = 20000
vmin = 10
vmax = 50

print n, s, vmin, vmax
for i in xrange(n):
    r = randint(10, 20)
    g = randint(10, 20)
    print randint(1, s - 1), r, g, randint(0, r + g)

