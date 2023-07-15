# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Dada una cadena s que representa una expresión, evaluar esta expresión y devolver su valor. La división de enteros debe truncar hacia cero. Puede asumir que la expresión dada es siempre válida. Todos los resultados intermedios estarán en el rango de [-231, 231 - 1].

# Nota: No está permitido utilizar ninguna función incorporada que evalúe cadenas como expresiones matemáticas, como eval().

# Ejemplo 1:
# Entrada: s = "3+2*2"
# Salida: 7

# Ejemplo 2:
# Entrada: s = " 3/2 "
# Salida: 1

# Ejemplo 3:
# Entrada: s = " 3+5 / 2 "
# Salida: 5


def calculadora(self, string: str) -> int:
    string = string.replace(" ", "")
    pila = []
    numeroActual = 0
    operador = "+"
    string = string + "+"
    for caracter in string:
        if caracter.isdigit():
            numeroActual = numeroActual * 10 + int(caracter)
        else:
            if operador is "+":
                pila.append(numeroActual)
            elif operador is "-":
                pila.append(-numeroActual)
            elif operador is "*":
                pila[-1] *= numeroActual
            elif operador is "/":
                pila[-1] = int(float(pila[-1]) / numeroActual)
            numeroActual = 0
            operador = caracter
    return sum(pila)
