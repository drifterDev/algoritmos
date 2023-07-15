# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


# Maximo comun divisor
#Algoritmo para hallar el maximo comun divisor

def gcd(a,b):
  x=max(abs(a),abs(b))
  y=min(abs(a),abs(b))
  r = x%y
  if r==0:
    return y
  else:
    while r>0:
      x = y
      y = r
      r = x%y
    return y

nums=list(map(int, input().split()))
result=gcd(nums[0], nums[1])
print("Maximo comun divisor de",nums[0],"y",nums[1],"=",result)