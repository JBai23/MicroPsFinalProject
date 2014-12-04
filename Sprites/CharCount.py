import sys
import os

infile = open(sys.argv[1], 'r')
intext = infile.read().replace('\n', '').strip()
infile.close()

print len(intext)