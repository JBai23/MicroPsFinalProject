
infile = open('SpecOriginal.txt', 'r')
outfile = open('out4.txt', 'w')

lines = infile.read().split('\n')

x = 0
pkmn = 0

while x < len(lines):
	name = lines[x + 2].split('.')[0]
	#newn = 'specs_all[' + str(pkmn) + ']'
	for i in range(12):
		#outfile.write(lines[x].replace(name, newn) + '\n')
		x +=  1
	outfile.write(str(pkmn + 1) + ': ' + name + '\n')
	pkmn += 1