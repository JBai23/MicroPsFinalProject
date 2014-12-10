from sets import Set
import numpy as np
import cv2
import sys
import os

fname = sys.argv[1].split("_")[0]

img = cv2.imread(sys.argv[1])
imgr = np.array(img);

for i in range(imgr.shape[0]):
	imgr[i] = imgr[i][::-1]

cv2.imwrite(fname + '_L.png', img)
cv2.imwrite(fname + '_R.png', imgr)

# # write our file
# out = open(os.path.splitext(sys.argv[1])[0] + '.txt', 'w') # don't pass a .txt in argv

# palette = sorted(list(uniqc))
# while len(palette) < 16:
# 	palette.append((0,0,0))

# # write palette to file
# for color in palette:
# 	colorstr = ''
# 	for channel in color:
# 		colorstr += bin(channel)[2:].zfill(8)
# 	colorstr = colorstr.zfill(32)
# 	out.write(colorstr + '\n')

# # write image data to file
# for rows in img:
# 	for ele in rows:
# 		binstr = bin(palette.index(tuple(ele)[::-1]))[2:].zfill(4)
# 		out.write(binstr + '\n')

# out.close()