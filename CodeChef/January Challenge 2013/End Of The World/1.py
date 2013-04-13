print 8
for t in xrange(8):
    print 350
    for i in xrange(350):
        for j in xrange(350):
            print (10**7) - 1 - ((i + j) & 1), 
        print