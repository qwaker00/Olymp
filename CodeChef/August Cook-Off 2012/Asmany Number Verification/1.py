import sys

R, W = [[0, 0] for j in xrange(3344)], [[0, 0] for j in xrange(3344)]

OFF = 1555
R[OFF][0] = 1
R[OFF][1] = 1
for i in xrange(2, 111 + 1):
	for j in xrange(-(i+1)/2, (i+1)/2 + 1):
		for k in xrange(2):
			W[j + OFF][k] = R[j + OFF][1 - k]
			if k:
				W[j + OFF][k] += R[j - 1 + OFF][k]
			else:
				W[j + OFF][k] += R[j + 1 + OFF][k]
	sys.stdout.write(str(i) + ' ' + str(W[OFF][0] * 2) + '\n')
	R, W = W, R
		                    