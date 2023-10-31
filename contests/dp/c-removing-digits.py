# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

n=int(input())
dp=[0]
for i in range(1,10):
  dp.append(1)
dp.append(2)
if n<=10:
  print(dp[n])
else:
  for i in range(11, n+1):
    res=[]
    act=i
    for j in str(i):
      posible=act-int(j)
      if posible<i:
        res.append(dp[posible])
    dp.append(1+min(res))
  print(dp[n])
  