import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

while True:
	s = inp()
	if len(s) == 0: break
	print min(map(int, s.split()))
