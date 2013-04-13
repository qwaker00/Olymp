import random

d = []
for i in xrange(19):
    d.append(set([]))
d[0].add(1) 

for i in xrange(18):
    for x in d[i]:
        for k in xrange(1, 10):
            if x * k not in d[i + 1]:
                d[i + 1].add(x * k)

a = [sorted(list(d[i])) for i in xrange(19)]

print 36100
for i in xrange(36100):
    l = 36
    print l, a[18][i]
