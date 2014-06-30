import sys

N = 20

C = [0] * N
for i in range(N):
    C[i] = [0] * (i + 20)
    C[i][0] = 1
    for j in range(1, i + 1):
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j]

def check(solve):
    for i in range(0, N):
        for j in range(0, i + 1):
            if C[i][j] != solve(i, j):
                sys.stderr.write('%d %d %s %s\n' % (i, j, C[i][j], solve(i, j)))
                return 'bad'
    return 'good'



#import j1_01
#print (check(j1_01.solve))

import j1_02
print (check(j1_02.solve))
sys.exit()

import j1_03
print (check(j1_03.solve))

import j1_04
print (check(j1_04.solve))

import j1_05
print (check(j1_05.solve))

import j1_06
#print (6, check(j1_06.solve)
print ('good')

import j1_07
#print (7, check(j1_07.solve)
print ('bad')

import j1_08
print (check(j1_08.solve))

#import j1_09
#print (check(j1_09.solve))
print ('bad')

import j1_10
print (check(j1_10.solve))

import j1_11
print (check(j1_11.solve))
