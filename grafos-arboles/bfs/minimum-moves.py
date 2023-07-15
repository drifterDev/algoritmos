# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

def minimum_moves(origenx, origeny, objetivox, objetivoy):
    direcciones = [
        [-1, 2],
        [1, 2],
        [-1, -2],
        [1, -2],
        [2, -1],
        [2, 1],
        [-2, -1],
        [-2, 1],
    ]
    visitados = set()
    cantidad_movimientos = 0
    cola = [[origenx, origeny]]
    while cola:
        for _ in range(len(cola)):
            actualx, actualy = cola.pop(0)
            if actualx == objetivox and actualy == objetivoy:
                return cantidad_movimientos
            if (actualx, actualy) in visitados:
                continue
            visitados.add((actualx, actualy))
            for direccion in direcciones:
                cola.append([actualx + direccion[0], actualy + direccion[1]])
        cantidad_movimientos += 1
    return cantidad_movimientos
