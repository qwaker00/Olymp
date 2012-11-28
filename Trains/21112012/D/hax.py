import sys, os, random

rand = random.randint
out = open('dragon.out', 'w')
inp = open('dragon.in')

n, d = map(int, inp.readlines()[0].rstrip().split(' '))
x = 1
for i in xrange(n - 1):
    x *= 10
if x % d == 0:
    out.write(str(x) + '\n')
else:
    x /= d
    x += 1
    x *= d
    if len(str(x)) == n:
        out.write(str(x) + '\n')
    else:
        out.write('No solution\n')
out.close()