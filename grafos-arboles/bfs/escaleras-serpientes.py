# Se le da un tablero de matriz entera n x n en el que las casillas están etiquetadas de 1 a n2 al estilo Boustrophedon empezando por la parte inferior izquierda del tablero (es decir, tablero[n - 1][0]) y alternando la dirección de cada fila. Se comienza en la casilla 1 del tablero. En cada movimiento, partiendo de la casilla curr, haz lo siguiente
# Elige una casilla de destino próxima con una etiqueta en el rango [curr + 1, min(curr + 6, n2)]. Esta elección simula el resultado de una tirada estándar de 6 caras: es decir, siempre hay como máximo 6 destinos, independientemente del tamaño del tablero.
# Si el siguiente tiene una serpiente o escalera, debes moverte al destino de esa serpiente o escalera. En caso contrario, te mueves a siguiente.

# El juego termina cuando se llega a la casilla n2. Una casilla del tablero en la fila r y la columna c tiene una serpiente o escalera si tablero[r][c] != -1. El destino de esa serpiente o escalera es el tablero[r][c]. Las casillas 1 y n2 no tienen serpiente o escalera. Ten en cuenta que sólo puedes coger una serpiente o escalera como máximo una vez por movimiento. Si el destino de una serpiente o escalera es el inicio de otra serpiente o escalera, no sigues la siguiente serpiente o escalera. Por ejemplo, suponga que el tablero es [[-1,4],[-1,3]], y en el primer movimiento, su casilla de destino es la 2. Sigue la escalera hasta la casilla 3, pero no sigue la escalera posterior hasta la 4. Devuelve el menor número de movimientos necesarios para llegar a la casilla n2. Si no es posible llegar a la casilla, devuelve -1.

# Ejemplo 1:
# Entrada:
# board=[[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
# Salida: 4
# Explicación: Al principio, empiezas en la casilla 1 (en la fila 5, columna 0). Decides moverte a la casilla 2 y debes llevar la escalera hasta la casilla 15. Luego decides moverte a la casilla 17 y debes llevar la serpiente a la casilla 13. Luego decides moverte a la casilla 14 y debes llevar la escalera a la casilla 35. Entonces decides moverte a la casilla 36, terminando el juego. Este es el menor número posible de movimientos para llegar a la última casilla, así que devuelve 4.


def snakesAndLadders(tablero: list[list[int]]) -> int:
    tablero.reverse()
    tableroPlano = [0]
    for i, fila in enumerate(tablero):
        if i % 2 == 0:
            tableroPlano += fila
        else:
            tableroPlano += fila[::-1]
    cola = [1]
    casillasVisitadas = set()
    movimientos = 0
    while cola:
        siguienteNivel = []
        while cola:
            casilla = cola.pop()
            if casilla == len(tableroPlano) - 1:
                return movimientos
            for i in range(1, 7):
                if (
                    casilla + i <= len(tableroPlano) - 1
                    and casilla + i not in casillasVisitadas
                ):
                    casillasVisitadas.add(casilla + i)
                    if tableroPlano[casilla + i] != -1:
                        siguienteNivel.append(tableroPlano[casilla + i])
                    else:
                        siguienteNivel.append(casilla + i)
        cola = siguienteNivel
        movimientos = movimientos + 1
    return -1
