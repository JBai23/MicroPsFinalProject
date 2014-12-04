import sys
import os

infile = open(sys.argv[1], 'rb')
intext = infile.read()#.replace('\n', '')
infile.close()

print len(intext)


outfile = open(os.path.splitext(sys.argv[1])[0] + '_REVERSED.txt', 'w')

bits = 0

# assumes everything is aligned correctly, does not pad anything
while (intext != ''):
	b = bin(ord(intext[0]))[2:].zfill(8)
	#print b
	outfile.write(b)	
	intext = intext[1:]
	bits += 8

print bits

outfile.close()
