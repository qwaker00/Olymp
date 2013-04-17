import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

n = 1000000

print n

size = 0

for i in xrange(n):
	req = ''
	if size > 0 and rand(0, 1) == 0:
		req += '-' + random.choice('LR')
		size -= 1
	else:
		req += '+' + random.choice('LR')
		req += ' ' + str(rand(1, 10**9))
		size += 1
 	print req

