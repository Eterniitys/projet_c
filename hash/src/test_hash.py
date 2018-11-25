strings = ["abc","bac","bca","acb","cba","cab"]
hashes = dict()

def hash_kilian(string):
	output = [0,42,69]
	index = 0

	for char in string:
		output[index] = output[index] ^ (ord(char)+index) % 256
		index = (index + 1) % 3
	o = (output[0] + output[1] + output[2]) % 256
	return o

collisions = 0

for string in strings:
	h = hash_kilian(string)
	if h in hashes:
		print("Collision between {} and {}.".format(hashes[h], string))
		collisions+=1
	else:
		hashes[h] = string

print("{:%} collisions".format(collisions/len(strings)))
