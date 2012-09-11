
f = [1, 1, 1]
for i in xrange(102):
	f.append(f[-1] + f[-2] + f[-3])

M = 1000000007
print f[-3] % M, f[-2] % M, f[-1] % M