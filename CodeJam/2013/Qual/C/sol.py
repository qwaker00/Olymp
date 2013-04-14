import sys


def supergen(l):
    buf = ['0'] * (l + 1)
    for w in xrange(l + 1):
        buf[w] = '1'
        for x in xrange(0 if w == 0 else w + 1, l + 1):
            buf[x] = '1'
            for y in xrange(0 if x == 0 else x + 1, l + 1):
                buf[y] = '1'
                for z in xrange(0 if y == 0 else y + 1, l + 1):
                    buf[z] = '1'
                    yield ''.join(buf[1:])
                    buf[z] = '0'
                buf[y] = '0'
            buf[x] = '0'
        buf[w] = '0'

cand = []
cand.append('1')
cand.append('2')
cand.append('3')
cand.append('11')
cand.append('22')

for l in xrange(3, 0):
    cand.append(''.join(['2', '0' * (l - 2), '2']))
    if (l & 1) == 1:
        cand.append(''.join(['2', '0' * ((l - 3) / 2), '1', '0' * ((l - 3) / 2), '2']))

    if (l & 1) == 0:
        ll = (l - 2) / 2
        for k in supergen(ll):
            cand.append(''.join(['1', k, k[::-1], '1']))
    else:
        ll = (l - 2) / 2
        for k in supergen(ll):
            cand.append(''.join(['1', k, '0', k[::-1], '1']))
            cand.append(''.join(['1', k, '1', k[::-1], '1']))
            cand.append(''.join(['1', k, '2', k[::-1], '1']))

ans = []
for c in cand:
    si = int(c) ** 2
    s = str(si)
    if s[::-1] == s:
        ans.append(si)
ans = sorted(ans)

print 'Calced... Length %d' % len(ans)

inp = open('in')
out = open('out', 'w')

T = int(inp.readline())
for __it in xrange(T):
    A, B = map(int, inp.readline().split())
    print __it + 1, A, B
    res = 0

    for c in ans:
        if c >= A and c <= B:
            res += 1

    out.write('Case #%d: %d\n' % (__it + 1, res))
