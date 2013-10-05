import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline


def fix(c):
    while c and c[-1] == 0:
        del c[-1]
    return c

def mul(x, y):
    c = [0 for i in xrange(len(x) + len(y) - 1)]
    for i in xrange(len(x)):
        for j in xrange(len(y)):
            c[i + j] = c[i + j] ^ (x[i] * y[j])
    return fix(c)

def add(x, y):
    c = [0 for i in xrange(max(len(x), len(y)))]
    for i in xrange(len(x)):
        c[i] = c[i] ^ x[i]
    for i in xrange(len(y)):
        c[i] = c[i] ^ y[i]
    return fix(c)

try:    
    f = open('eq.in', 'r')
    a1 = fix(map(int, reversed(f.readline().rstrip().split(' ')[1:])))
    b1 = fix(map(int, reversed(f.readline().rstrip().split(' ')[1:])))
    c1 = fix(map(int, reversed(f.readline().rstrip().split(' ')[1:])))

    a2 = fix(map(int, reversed(f.readline().rstrip().split(' ')[1:])))
    b2 = fix(map(int, reversed(f.readline().rstrip().split(' ')[1:])))
    c2 = fix(map(int, reversed(f.readline().rstrip().split(' ')[1:])))

    f = open('eq.out', 'r')
    x = fix(map(int, reversed(f.readline().rstrip().split(' ')[1:])))
    y = fix(map(int, reversed(f.readline().rstrip().split(' ')[1:])))


    r1 = add(mul(a1, x), mul(b1, y))
    r2 = add(mul(a2, x), mul(b2, y))

    if r1 != c1:
        print 'ERRR1'
        while True:
            pass
        sys.exit(1)
    if r2 != c2:
        print 'ERRR2'
        while True:
            pass
        sys.exit(2)
    print 'OK'
except Exception as e:
    while True:
        pass
    
