import copy
import sys


print sys.argv[1], sys.argv[2]
infile = open(sys.argv[1], 'r')
lines = infile.read().split('\n')
ln = 0

trainer_base = {
	'name' : '',
	'pokemon_count' : 0,
	'pokemon' : []
}

pokemon_base = {
	'species' : 0,
	'level' : 0,
	'hp_ev' : 0,
	'hp_iv' : 0,
	'attack_ev' : 0,
	'attack_iv' : 0,
	'defense_ev' : 0,
	'defense_iv' : 0,
	'sattack_ev' : 0,
	'sattack_iv' : 0,
	'sdefense_ev' : 0,
	'sdefense_iv' : 0,
	'speed_ev' : 0,
	'speed_iv' : 0,
	'nature' : 0,
	'move_count' : 0,
	'moves' : []
}

ordered_keys = [
	'name', 'pokemon_count',
	'species', 'level',
	'hp_ev', 'hp_iv',
	'attack_ev', 'attack_iv',
	'defense_ev', 'defense_iv',
	'sattack_ev', 'sattack_iv',
	'sdefense_ev', 'sdefense_iv',
	'speed_ev', 'speed_iv',
	'nature', 'move_count',
	'moves'
]

ordered_tkeys = [
	'name', 'pokemon_count', 'pokemon'
]

ordered_pkeys = [
	'species', 'level',
	'hp_ev', 'hp_iv',
	'attack_ev', 'attack_iv',
	'defense_ev', 'defense_iv',
	'sattack_ev', 'sattack_iv',
	'sdefense_ev', 'sdefense_iv',
	'speed_ev', 'speed_iv',
	'nature', 'move_count',
	'moves'
]

def getNext():
	global ln, lines
	ln += 1
	return lines[ln - 1]

def isString(key):
	return key == 'name'

def is_valid(key, input):
	if key == 'name':
		return (len(input) >= 1) and (len(input) <= 12)
	elif key == 'pokemon_count':
		return (input >= 1) and (input <= 6)
	elif key == 'species':
		return (input >= 1) and (input <= 151)
	elif key == 'level':
		return (input >= 1) and (input <= 100)
	elif '_ev' in key:
		return (input >= 0) and (input <= 252) # does not check if sum is 510 or less
	elif '_iv' in key:
		return (input >= 0) and (input <= 31)
	elif key == 'nature':
		return (input >= 0) and (input <= 24)
	elif key == 'move_count':
		return (input >= 1) and (input <= 6)
	elif key == 'moves':
		return (input >= 0) and (input <= 109)
	else:
		return False

def getMsg(key):
	if key == 'name':
		return key.upper() + ' [input a string between 1 and 12 characters in length]'
	elif key == 'pokemon_count':
		return key.upper() + ' [input an integer between 1 and 6 inclusive]'
	elif key == 'species':
		return key.upper() + ' [input an integer between 1 and 151 inclusive]'
	elif key == 'level':
		return key.upper() + ' [input an integer between 1 and 100 inclusive]'
	elif '_ev' in key:
		return key.upper() + " [input an integer between 0 and 252 inclusive]" #  - all EV's must sum to 510 or less
	elif '_iv' in key:
		return key.upper() + ' [input an integer between 1 and 31 inclusive]'
	elif key == 'nature':
		return key.upper() + ' [input an integer between 0 and 24 inclusive]'
	elif key == 'move_count':
		return key.upper() + ' [input an integer between 1 and 4 inclusive]'
	elif key == 'moves':
		return key.upper() + ' [input an integer between 0 and 109 inclusive]'
	else:
		return False	

def getPokemon():
	p = copy.deepcopy(pokemon_base)
	for key in ordered_pkeys:
		if key != 'moves':
			p[key] = int(getNext())
			if not is_valid(key, p[key]):
				print getMsg(key)
				exit()
		else:
			for i in range(p['move_count']):
				p[key].append(int(getNext()))
				if not is_valid(key, p[key][i]):
					print getMsg(key), "Line: " + str(ln - 1)
					exit()
			for i in range(p['move_count'], 4):
				p[key].append(0)
	return p

def getTrainer():
	t = copy.deepcopy(trainer_base)
	for key in ordered_tkeys:
		if key != 'pokemon':
			if isString(key):
				t[key] = getNext().upper()
			else:
				t[key] = int(getNext())
			if not is_valid(key, t[key]):
				print getMsg(key), "Line: " + str(ln - 1)
				exit()
		else:
			for i in range(t['pokemon_count']):
				t[key].append(getPokemon())

			for i in range(t['pokemon_count'], 6):
				t[key].append(copy.deepcopy(pokemon_base))
				for j in range(4):
					t[key][i]['moves'].append(0)
	return t

def mkData(trainer):
	data = []
	data.append(trainer['name'])
	for i in range(len(trainer['name']), 16):
		data.append(0)
	data.append(trainer['pokemon_count'])
	for i in range(6):
		p = trainer['pokemon'][i]
		for key in ordered_pkeys:
			if key != 'moves':
				data.append(p[key])
			else:
				for j in range(4):
					data.append(p[key][j])
	return data


d = mkData(getTrainer())
print d
print len(d) + len(d[0]) - 1

out = open(sys.argv[2], 'wb')
out.write(d[0])
for i in range(1, len(d)):
	out.write(chr(d[i]))
out.close()


#getPokemon()