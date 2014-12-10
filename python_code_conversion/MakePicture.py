import numpy as np
import cv2
import sys

infile = open(sys.argv[1], 'r')

data = infile.read().replace('\n', '').strip()

colors = []
for colornum in range(16):
	line = data[0:32]
	data = data[32:]
	bytes = [line[i:i + 8] for i in range(0, len(line), 8)][1:]
	color = (int(bytes[2], 2), int(bytes[1], 2), int(bytes[0], 2))
	#color = (color[0], color[1], 255)
	colors.append(color)
	print color


img = np.zeros((64,64,3))



#count = 0

#while data != '':
for count in range(64 * 64):
	pixel = data[0:4]
	data = data[4:]
	img[count / 64][count % 64] = colors[int(pixel, 2)]
	#count += 1

cv2.imwrite('00.png', img)