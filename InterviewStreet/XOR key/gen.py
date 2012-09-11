import random

ri = lambda : random.randint(0, 2**15 - 1)
T = 6
N = 100000
M = 50000


print T
for t in xrange(T):
	print '%d %d' % (N, M)
	for i in xrange(N): print ri(), 
	print
	for i in xrange(M):
		p = random.randint(1, N)
		q = random.randint(p, N)
		print ri(), p, q
