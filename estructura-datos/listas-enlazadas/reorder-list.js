class Nodo {
  constructor(valor = 0, siguiente = null) {
    this.valor = valor;
    this.siguiente = siguiente;
  }
}

// O(n)
const reorderList = (cabeza) => {
  if (!cabeza || !cabeza.siguiente || !cabeza.siguiente.siguiente) {
    return cabeza;
  }
  let rapido = cabeza.siguiente;
  let lento = cabeza;
  // O(n)
  while (rapido && rapido.siguiente) {
    rapido = rapido.siguiente.siguiente;
    lento = lento.siguiente;
  }
  const comienzoSegundaMitad = lento.siguiente;
  let actual = comienzoSegundaMitad;
  let anterior = null;
  let tmp;
  // O(n)
  while (actual) {
    tmp = actua.siguiente;
    actual.siguiente = anterior;
    anterior = actual;
    actual = tmp;
  }
  let p1 = cabeza;
  let p2 = anterior;
  // O(n)
  while (p2) {
    tmp = p1.siguiente;
    p1.siguiente = p2;
    p1.siguiente.siguiente = tmp;
    p2.siguiente = tmp;
    p1 = tmp;
  }
};
