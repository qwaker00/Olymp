#!/usr/bin/env python
import random

n = random.randint(1, 10)
m = random.randint(0, n * (n - 1) / 2)

print n, m
for i in xrange(m):
    x = random.randint(1, n - 1)
    y = random.randint(x + 1, n)

    print x, y
