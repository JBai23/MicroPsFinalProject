import sys
import os

infile = open(sys.argv[1], 'r')
intext = infile.read().replace('\n','').strip()
infile.close()

outfile = open(os.path.splitext(sys.argv[1])[0] + "_STRIPPED" + os.path.splitext(sys.argv[1])[1], 'w')
outfile.write(intext)
outfile.close()