import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

n = q = 100000

a = []
s = 0
while True:
    x = rand(1, 1000)
    if s + x > 100000: break
    a.append(x)
    s += x
m = len(a)

print n, m, q
for i in xrange(n):
    print rand(-10**8, 10**8),
print

for i in xrange(m):
    print a[i], 
    for j in xrange(a[i]):
        print rand(1, n), 
    print

for i in xrange(q):
    if rand(0, 1) == 0:
        print '? ' + str(rand(1, m))
    else:
        print '+ ' + str(rand(1, m)) + ' ' + str(rand(-10**8, 10**8))