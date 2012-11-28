import sys
import random


print 300, 300, ' ', 
for i in xrange(100):
    sys.stdout.write(random.choice('1234567890'))

for i in xrange(299):
    for j in xrange(299):
        sys.stdout.write(random.choice('NLR')) 
    print