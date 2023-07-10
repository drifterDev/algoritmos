def profundidad(raiz):
    if not raiz:
        return 0
    izquierda = profundidad(raiz.izquierda)
    derecha = profundidad(raiz.derecha)
    if not izquierda:
        return derecha + 1
    elif not derecha:
        return izquierda + 1
    else:
        return min(izquierda, derecha) + 1
