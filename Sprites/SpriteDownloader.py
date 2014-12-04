import urllib


infile = open('Pokemon Gen1 Names.csv', 'r')
names = infile.read().split()
print names


baseurl = 'http://img.pokemondb.net/sprites/firered-leafgreen/normal/'

num = 1

for name in names:
	url = baseurl + name.lower() + '.png'
	fname = str(num).zfill(3) + '_' + name + '.png'
	print url, fname
	urllib.urlretrieve(url, fname)
	num += 1