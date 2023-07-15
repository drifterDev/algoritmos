# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

alfabeto=list("abcdefghijklmnopqrstuvwxyz")
words=input().split()
orden=input()
dic={}
for i in range(26):
    dic[orden[i]]=alfabeto[i]
m=len(words)
for y in range (m):
    n=len(words[y])
    new=""
    for j in range (n):
        new+=dic[words[y][j]]
    words[y]=new
orden=sorted(words)
if (words==orden):
    print("YES")
else:
    print("NO")

