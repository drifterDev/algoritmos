# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

for i in range(int(input())):
    n=input()
    lista=[]
    for j in range(len(n)):
        if n[j]=="0":
            continue
        ceros="0"
        lista.append(n[j]+(ceros*(len(n)-1-j)))
    print(len(lista))
    print(" ".join(lista))