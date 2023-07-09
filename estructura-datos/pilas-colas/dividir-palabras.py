# Dada una cadena s y un diccionario de cadenas wordDict, devuelve true si s puede segmentarse en una secuencia separada por espacios de una o más palabras del diccionario. Tenga en cuenta que la misma palabra del diccionario puede reutilizarse varias veces en la segmentación.

#  Ejemplo 1:
#     Entrada: s = "leetcode", wordDict = ["leet", "code"]
#     Salida: true
# Explicación: Devuelve true porque "leetcode" puede ser segmentado como "leet code".

# Ejemplo 2:
#     Entrada: s = "manzanamanzana", wordDict = ["manzana", "pluma"]
#     Salida: true
# Explicación: Devuelve true porque "manzana-manzana" se puede segmentar como "manzana manzana". (Tenga en cuenta que se permite reutilizar una palabra del diccionario).


def dividirPalabras(self, s: str, wordDict: list[str]) -> bool:
    inicio = 0
    pila = [inicio]
    visitado = set()
    while pila:
        inicio = pila.pop()
        if inicio in visitado:
            continue
        visitado.add(inicio)
        for word in wordDict:
            if s[inicio:].startswith(word):
                x = len(word)
                if x == len(s[inicio:]):
                    return True
                pila.append(inicio + x)
    return False
