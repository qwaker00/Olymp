import random, sys
n = 150000
print n
for i in xrange(n):
    print random.randint(-1000, 1000),
print
g = [[] for i in xrange(n)]
for i in xrange(1, n):        
    x = random.randint(0, i - 1)
    print x, i
    g[x].append(i)
print 100000
spec = 0
removed = set()

def rem(x):
    if x in removed: return
    removed.add(x)
    for y in g[x]:
        rem(y)

for i in xrange(100000):
    t = random.choice([1, 1, 3, 2, 2, 2, 4, 4, 4])
    while t == 3 and len(removed) == n - 1:
        t = random.choice([1, 1, 3, 2, 2, 2, 4, 4, 4])
        
    if t == 1:
        print 1
        k = random.randint(0, n - 1)
        while k in removed:
            k = random.randint(0, n - 1)            
        v = random.randint(-1000, 1000)
        print k, v
        n += 1
        g.append([])
    elif t == 2:
        print 2
        k = random.randint(0, n - 1)
        while k in removed:
            k = random.randint(0, n - 1)            
        v = random.randint(-1000, 1000)
        print k, v
    elif t == 3:
        print 3
        k = random.randint(0, n - 1)
        while k == 0 or k in removed:
            k = random.randint(0, n - 1)            
        print k
        rem(k)
    elif t == 4:
        print 4
        k = random.randint(0, n - 1)
        while k in removed:
            k = random.randint(0, n - 1)            
        print k
#    print >>sys.stderr, i, n, len(removed)
