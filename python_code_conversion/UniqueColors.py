from sets import Set
import numpy as np
import cv2
import os
from os import walk

mypath = os.getcwd()

f = []
for (dirpath, dirnames, filenames) in walk(mypath):
	#print os.path.join(dirpath, filenames)
	
	for filename in filenames:
		fname, ext = os.path.splitext(filename)
		if ext == '.png':
			f.append(filename)
	break

print f

n = 1
most = 0
most_id = 0
for imgname in f:
	uniqc = set([])
	img = cv2.imread(imgname)
	for rows in img:
		for ele in rows:
			uniqc.add(tuple(ele))
	if len(uniqc) > most:
		most = len(uniqc)
		most_id = n

	# write compressed file
	fname, ext = os.path.splitext(imgname)
	outname = fname + '.txt'
	print outname
	out = open(outname, 'w')
	uniqcolor = sorted(list(uniqc))
	while len(uniqcolor) < 16:
		uniqcolor.append((0,0,0))
	for color in uniqcolor:
		colorstr = ''
		for channel  in color:
			binstr = bin(channel)[2:].zfill(8)
			colorstr += binstr
		colorstr = colorstr.zfill(32)
		out.write(colorstr + '\n')
	for rows in img:
		for ele in rows:
			binstr = bin(uniqcolor.index(tuple(ele)))[2:].zfill(4)
			out.write(binstr + '\n')

	out.close()
	n += 1


print most
print most_id



	#img[1][0] = [128, 128, 128]
	#cv2.imwrite('00.png', img)