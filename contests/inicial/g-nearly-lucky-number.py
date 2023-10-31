# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

x=input()
lucky=0
for j in range (len(x)):
  if x[j] =="4" or x[j]=="7":
    lucky+=1
if lucky==4 or lucky==7:
  print("YES")
else:
  print("NO")