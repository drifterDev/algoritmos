valores = [20, 50, 30, 40, 50, 10]
a = set()
for v in valores:
	a.add(v)
b = set(valores)
print(len(a))
print(40 in b)
a.remove(50)
print(a)
c = set([0, 1, 1, 2, 3, 5, 8, 13, 21])
d = set([2, 3, 5, 7, 11, 13, 17, 19])
print(c & d) #print(c.intersection(d))
print(c | d) #print(c.union(d))
print(c - d) #print(c.difference(d))
print(c ^ d) #print(c.symmetric_difference(d))
print(c <= d) #print(c.issubset(d))
