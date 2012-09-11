import sys

f = sys.argv[1]
a = map(int, open(f).readlines()[0].split())
n = max(a)
print n
if len(a) != n:
	print '3'
	sys.exit(3)
was = {}
for x in a:
	if x < 1 or x > n:
		print '1'
		sys.exit(1)
	if x in was:
		print '2'
		sys.exit(2)
	was[x] = 1

print 'OK'
