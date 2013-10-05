import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline


def r(n):
    return [rand(0, 1) for i in xrange(n)]

def mul(x, y):
    c = [0 for i in xrange(len(x) + len(y) - 1)]
    for i in xrange(len(x)):
        for j in xrange(len(y)):
            c[i + j] = c[i + j] ^ (x[i] * y[j])
    return c

def add(x, y):
    c = [0 for i in xrange(max(len(x), len(y)))]
    for i in xrange(len(x)):
        c[i] = c[i] ^ x[i]
    for i in xrange(len(y)):
        c[i] = c[i] ^ y[i]
    return c

l = 5
a1 = r(l)
b1 = r(l)
a2 = r(l)
b2 = r(l)
x = r(l)
y = r(l)

c1 = add(mul(a1, x), mul(b1, y))
c2 = add(mul(a2, x), mul(b2, y))

f = open('eq.in', 'w')
print >>f, len(a1) - 1, ' '.join(map(str, reversed(a1)))
print >>f, len(b1) - 1, ' '.join(map(str, reversed(b1)))
print >>f, len(c1) - 1, ' '.join(map(str, reversed(c1)))

print >>f, len(a2) - 1, ' '.join(map(str, reversed(a2)))
print >>f, len(b2) - 1, ' '.join(map(str, reversed(b2)))
print >>f, len(c2) - 1, ' '.join(map(str, reversed(c2)))


print >>f, len(x) - 1, ' '.join(map(str, reversed(x)))
print >>f, len(y) - 1, ' '.join(map(str, reversed(y)))
