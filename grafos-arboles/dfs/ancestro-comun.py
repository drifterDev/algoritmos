# Dado un árbol binario, encuentre el ancestro común más bajo (LCA) de dos nodos dados en el árbol. Según la definición de LCA en Wikipedia “El mínimo común antecesor se define entre dos nodos p y q como el nodo más bajo de T que tiene tanto p como q como descendientes (donde permitimos que un nodo sea descendiente de sí mismo).”

# Ejemplo 1:
# Entrada: raíz = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
# Salida: 3
# Explicación: El ACV de los nodos 5 y 1 es 3.

# Ejemplo 2:
# Entrada: raíz = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
# Salida: 5
# Explicación: El LCA de los nodos 5 y 4 es 5, ya que un nodo puede ser descendiente de sí mismo según la definición de ACV.
# Ejemplo 3:
# Entrada: raíz = [1,2], p = 1, q = 2
# Salida: 1


class TreeNode:
    def __init__(self, val=0, izquierda=None, derecha=None):
        self.val = val
        self.izquierda = izquierda
        self.derecha = derecha


def LCA(raiz: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
    if not raiz or raiz == p or raiz == q:
        return raiz
    izquierda = LCA(raiz.izquierda, p, q)
    derecha = LCA(raiz.derecha, p, q)
    if izquierda and derecha:
        return raiz
    return izquierda or derecha
