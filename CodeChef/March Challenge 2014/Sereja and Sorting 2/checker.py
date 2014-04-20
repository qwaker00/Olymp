inp = open('.in')
n = int(inp.readline())
a = map(int, inp.readline().split())

ouf = open('.out')
m = int(ouf.readline())
score = 0
for i in xrange(m):
#    print a
    l, r = map(int, ouf.readline().split())
    l -= 1
    r -= 1
    a = a[:l] + list(reversed(a[l:r+1])) + a[r+1:]
    score += n + r - l + 1

for i, j in zip(a, a[1:]):
    assert i <= j
print a
print score