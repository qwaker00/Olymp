from decimal import *
#getcontext().prec = 10

n, t = map(int, raw_input().split())
p = raw_input().split()
pp = range(len(p))
for i in xrange(n):
    p[i] = Decimal(p[i])
    pp[i] = Decimal(1) - p[i]
q = raw_input().split()
for i in xrange(n):
    q[i] = Decimal(q[i])

f = [0] * (n + 1)
for i in xrange(n + 1):
    f[i] = [0] * (t + 3)
    for j in xrange(t + 3):
        f[i][j] = Decimal(0)

for i in xrange(t + 1):
    f[n][i] = Decimal(1)

for i in xrange(n - 1, -1, -1):
    for j in xrange(t, -1, -1):
        res1 = p[i] * f[i + 1][j + 1];
        res2 = (pp[i] * q[i] * f[i][j + 2] +
                p[i] * f[i + 1][j + 2]);
        f[i][j] = max(res1, res2);

print '%.15f' % f[0][0]
