
infile = open('MoveOriginal.txt', 'r')
outfile = open('out3.txt', 'w')

lines = infile.read().split('\n')

x = 0
mvs = 0

while x < len(lines):
	name = lines[x + 2].split('.')[0]
	#newn = 'moves_all[' + str(mvs) + ']'
	for i in range(13):
		# outfile.write(lines[x].replace(name, newn) + '\n')
		x +=  1
	outfile.write(str(mvs) + ': ' + name + '\n')
	mvs += 1