import sys

inf = open('new.txt', 'r')
ouf = open('code.ws', 'wb')
for i in inf:
    i = i.strip().replace(' ', '').replace('\t', '').replace('\n', '').replace('T', '\t').replace('S', ' ').replace('L', chr(10))
    if i.find('#') != -1:
        i = i[:i.find('#')]
    ouf.write(i)
