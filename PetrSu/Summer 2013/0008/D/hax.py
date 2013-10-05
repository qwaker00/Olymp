import sys

s = list(sys.stdin.read())
for i in range(len(s)):
	if ord(s[i]) < 32:
		s[i] = ' '
sys.stdout.write(''.join(s) + '\n')

