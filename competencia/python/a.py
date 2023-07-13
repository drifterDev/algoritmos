n = int(input())
s = input()
t = input()
p1 = -1
p2 = -1
res = 0
letrass = {}
letrast = {}
for i in range(n):
    if s[i] != t[i]:
        res += 1
        letrass[s[i]] = i
        letrast[t[i]] = i
numero = res
respuestas = {}
minimo = 200000
pasa = False
for j in letrast:
    if j in letrass:
        p1 = letrass[j]
        p2 = letrast[j]
        res -= 2 if t[p1] == s[p2] else 1
        respuestas[res] = [p1 + 1, p2 + 1]
        minimo = min(minimo, res)
        res = numero
        pasa = True
if not pasa:
    print(res)
    print("-1 -1")
else:
    print(minimo)
    p1 = respuestas[minimo][0]
    p2 = respuestas[minimo][1]
    print(str(p1) + " " + str(p2))
