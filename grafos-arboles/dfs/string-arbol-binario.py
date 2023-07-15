# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Dada la raíz de un árbol binario, construya una cadena formada por paréntesis y enteros a partir de un árbol binario con el modo de recorrido de preorden, y devuélvala. Omita todos los pares de paréntesis vacíos que no afecten a la relación de mapeo uno a uno entre la cadena y el árbol binario original.

# Ejemplo 1
# Entrada: raíz = [1,2,3,4]
# Salida: "1(2(4))(3)"
# Explicación: Originalmente, tiene que ser “1(2(4)())(3()())”, pero hay que omitir todos los pares de paréntesis vacíos innecesarios. Y será “1(2(4))(3)”

# Ejemplo 2:
# Entrada: raíz = [1,2,3,null,4]
# Salida: "1(2()(4))(3)"
# Explicación: Casi lo mismo que el primer ejemplo, excepto que no podemos omitir el primer par de paréntesis para romper la relación de mapeo uno a uno entre la entrada y la salida.


class TreeNode:
    def __init__(self, val=0, izquierda=None, derecha=None):
        self.val = val
        self.izquierda = izquierda
        self.derecha = derecha


class Solution:
    def tree2str(self, t: TreeNode) -> str:
        def dfs(raiz):
            if not raiz:
                return ""
            string = str(raiz.val)
            if not raiz.izquierda and not raiz.derecha:
                return string
            string += "(" + str(dfs(raiz.izquierda)) + ")"
            if raiz.derecha:
                string += "(" + str(dfs(raiz.derecha)) + ")"
            return string

        return dfs(t)
