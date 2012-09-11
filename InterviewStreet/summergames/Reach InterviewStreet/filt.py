

def good(s):
	if '..' in s: return False
	return  ('.ST.' in s) and ('MV.' in s)

f = open('1').readlines()
print 'OK'
ff = [s for s in f if good(s)]
print 'OK'
open('2','w').write(''.join(ff))