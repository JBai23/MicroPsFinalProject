import sys
import os

infile = open(sys.argv[1], 'r')
intext = infile.read().replace('\n','').strip()
infile.close()

outfile = open(os.path.splitext(sys.argv[1])[0], 'wb')

bytes = 0

# assumes everything is aligned correctly, does not pad anything
while (intext != ''):
	outfile.write(chr(int(intext[0:8], 2)))
	intext = intext[8:]
	bytes += 1

print bytes

outfile.close()