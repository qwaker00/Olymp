import re, sys

s = sys.stdin.read()
if re.search(r'\s?import\s+java\.', s):
    print 'Java'
elif re.search(r'\sint\s+main\([^)]*\)', s):
    print 'C'
else:
    print 'Python'