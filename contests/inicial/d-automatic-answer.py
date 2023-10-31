# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

t=int(input())
for _ in range(t):
  n=int(input())
  res=n*567
  res/=9
  res+=7492
  res*=235
  res/=47
  res-=498
  print(str(int(res))[-2])