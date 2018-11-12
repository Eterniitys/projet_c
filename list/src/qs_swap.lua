liste = {9,4,5,7,3,1,8}
liste2 = {8,1,3,7,5,4,9}

function show(liste)
	for k,v in ipairs(liste) do
		io.write(v.." ")
	end
	print()
end

function qs(liste, A, B)
	local watchA = A or 1
	local watchB = B or #liste
	if watchB - watchA <= 1 then
		return
	end
	local pivot = liste[(watchA + watchB) // 2]

	while liste[watchA] ~= pivot or liste[watchB] ~= pivot do
		if liste[watchA] < pivot then
			watchA = watchA + 1
		end
		if liste[watchB] > pivot then
			watchB = watchB - 1
		end
		if liste[watchA] >= pivot and liste[watchB] <= pivot then
			liste[watchA],liste[watchB] = liste[watchB],liste[watchA]
		end
	end
	qs(liste, A, watchA)
	qs(liste, watchB, B)
end

show(liste)
qs(liste)
show(liste)
print()

show(liste2)
qs(liste2)
show(liste2)
print()
