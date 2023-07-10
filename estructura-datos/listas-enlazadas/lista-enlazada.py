class listaEnlazada:
    def __init__(self, primerNodo) -> None:
        self.cabeza = primerNodo
        self.cola = primerNodo

    def setNodo(self, nodo):
        self.cola.siguiente = nodo
        self.cola = self.cola.siguiente

    def borrarNodo(self, nodo):
        nodo.siguiente = None

    def buscarNodo(self, valor):
        nodoActual = self.cabeza
        while nodoActual != None:
            if nodoActual.valor == valor:
                return nodoActual
            nodoActual = nodoActual.siguiente
        return None

    def borrarNodoPorValor(self, valor):
        nodoBorrar = self.buscarNodo(valor)
        if nodoBorrar != None:
            nodoBorrar.siguiente = None
