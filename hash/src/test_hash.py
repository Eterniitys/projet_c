def hash_kilian(string):
	output = [0,42,69]
	index = 0

	for char in string:
		#output[index] = output[index] ^ (ord(char)+index) % 256
		output[index] = output[index] ^ (ord(char)+index) % 256
		index = (index + 1) % 3
	o = (output[0] + output[1] + output[2]) % 256
	return o

def hash_johan(string):
	val = [19,46,67,123]
	i = 0
	for char in string:
		val[i%4] = ord(char) ^ (val[(i+1)%4]+i)
		i+=1
	somme = 0
	for k in val:
		somme += k
	
	return somme % 256

strings = []

inf = 33
sup = 36

for i in range(inf,sup):
	for j in range(inf,sup):
		for k in range(inf,sup):
			for l in range(inf,sup):
				strings.append(chr(i)+chr(j)+chr(k)+chr(l))


hashes_k = dict()
hashes_j = dict()

collisions_k = 0
collisions_j = 0

for string in strings:
	hk = hash_kilian(string)
	hj = hash_johan(string)
	if hk in hashes_k:
		print("K Collision between {} and {}.".format(hashes_k[hk], string))
		collisions_k+=1
	else:
		hashes_k[hk] = string

	if hj in hashes_j:
		print("J Collision between {} and {}.".format(hashes_j[hj], string))
		collisions_j+=1
	else:
		hashes_j[hj] = string

print("{:%} collisions k".format(collisions_k/len(strings)))
print("{:%} collisions j".format(collisions_j/len(strings)))
