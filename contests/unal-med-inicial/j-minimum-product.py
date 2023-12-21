# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

t=int(input())
for _ in range(t):
  a,b,x,y,n=map(int, input().split())
  tmp=min(n,a-x)
  tmp2=min(n,b-y)
  if(b-tmp2<a-tmp):
    a,b=b,a
    x,y=y,x
    tmp=tmp2
  a-=tmp
  n-=tmp
  if(n>0):
    b-=min(n,b-y)
  print(a*b)

  
  