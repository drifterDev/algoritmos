# Intercambio de nodos por parejas

# Dada una lista enlazada, intercambia cada dos nodos adyacentes y devuelve su cabeza. Debe resolver el problema sin modificar los valores de los nodos de la lista (es decir, sólo se pueden cambiar los propios nodos).

# Ejemplo 1:
#     Entrada: cabeza = [1,2,3,4]
#     Salida: [2,1,4,3]


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, cabeza: ListNode) -> ListNode:
        nodoActual = cabeza
        if nodoActual == None:
            return None
        while nodoActual != None and nodoActual.next != None:
            if nodoActual.val == nodoActual.next.val:
                nodoActual = nodoActual.next.next
            else:
                nodoActual.val, nodoActual.next.val = (
                    nodoActual.next.val,
                    nodoActual.val,
                )
                nodoActual = nodoActual.next.next
        return cabeza
