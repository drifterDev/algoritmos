# Nombre: Mateo Álvarez Murillo
# Cedula: 1128424116

import random
import math


# Para calcular la distancia de dos puntos de tres dimensiones
def distancia_puntos(punto1, punto2):
    distancia = 0
    for i in range(3):
        distancia += (punto1[i] - punto2[i]) ** 2
    distancia = math.sqrt(distancia)
    return distancia


# Para calcular la desviacion estandar de los promedios 20 obtenidos
def desviacion_estandar(distancias, promedio):
    n = len(distancias)
    suma = 0
    for dist in distancias:
        suma += (dist - promedio) ** 2
    res = math.sqrt(suma / (n - 1))
    return res


# Para calcular la media muestral de los 20 promedios calculados
def media_muestral(distancias):
    return sum(distancias) / len(distancias)


promedios = []
n_pares = 60
for i in range(20):
    promedio_i = 0
    for j in range(n_pares):
        punto_1 = [random.random(), random.random(), random.random()]
        punto_2 = [random.random(), random.random(), random.random()]
        promedio_i += distancia_puntos(punto_1, punto_2)
    promedio_i /= n_pares
    promedios.append(promedio_i)

media = media_muestral(promedios)
desviacion = desviacion_estandar(promedios, media)
t = 2.093
ic2 = t * (desviacion / math.sqrt(20))

print("Media muestral: " + str(media))
print("Desviacion estandar: " + str(desviacion))
print("IC para la media: " + str(media) + " +- " + str(ic2) + " con 95% de confianza")
