import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline


print 10
for i in xrange(20):
	for j in xrange(100 - rand(0, 10)):
		out( 'A' )
	print