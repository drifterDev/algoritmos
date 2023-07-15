# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Identidad de Bezout empleando el algoritmo de Euclides extendido
# Este algoritmo nos da los coeficientes que multiplican para que el resultado sea:
# a*s + b*t = 1

def bezout(a, b):
    r = b
    x = a    # almacenará al gcd(a, b)
    s = 0
    y = 1    # coeficiente de a
    t = 1
    z = 0    # coeficiente de b
    while r: #Hará el algoritmo hasta que el residuo sea 0
        q = x // r
        x, r = r, x % r
        y, s = s, y - q * s
        z, t = t, z - q * t
    return [y, z]

nums=list(map(int, input().split()))
expo=bezout(nums[0], nums[1])
print("(",nums[0],") * (",expo[0],") + (",nums[1],") * (",expo[1],") = 1")