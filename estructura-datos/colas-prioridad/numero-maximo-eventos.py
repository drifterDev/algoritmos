# Dado un array de eventos donde events[i] = [comienzoDiai, finalDiai]. Cada evento i comienza en comienzoDiai y termina en finalDiai. Puedes asistir a un evento i en cualquier día d donde startTimei <= d <= endTimei. Sólo se puede asistir a un evento en cualquier momento d. Devuelve el número máximo de eventos a los que puedes asistir.

# Ejemplo 1:
#     Entrada: eventos = [[1,2],[2,3],[3,4]]
#     Salida: 3
# Explicación: Puedes asistir a los tres eventos.

# Una forma de asistir a todos ellos es la que se muestra.
# Asistir al primer evento en el día 1.
# Asistir al segundo evento el día 2.
# Asistir al tercer evento el día 3.

# Ejemplo 2:
#     Entrada: eventos= [[1,2],[2,3],[3,4],[1,2]]
#     Salida: 4


from heapq import heappop, heappush
import sys


def maxEventos(self, eventos: list[list[int]]) -> int:
    eventos.sort(key=lambda x: x[0])
    cuentaAtendidos = 0
    listaEventosAtendidos = []
    dia = 1
    for comienzo, final in eventos + [[sys.maxsize, 0]]:
        while dia < comienzo and listaEventosAtendidos:
            evento = heappop(listaEventosAtendidos)
            if dia <= evento:
                cuentaAtendidos += 1
                dia += 1
        dia = max(dia, comienzo)
        heappush(listaEventosAtendidos, final)
    return cuentaAtendidos
