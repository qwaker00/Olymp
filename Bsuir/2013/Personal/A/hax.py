import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

gl = 'aeiouAEIOU'
for line in open('hax.cpp'):
    cnt = sum(1 for c in line if c in gl)
    if cnt & 1:
        print line.strip() + ' //a'
    else:
        print line.strip()
