// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

public class ListaEnlazada {
 protected Nodo cabeza; 
 protected Nodo cola;

 public ListaEnlazada(Nodo primerNodo){
  this.cabeza=primerNodo;
  this.cola=primerNodo;
 }

 public void setNodo(Nodo nodo){
  this.cola.siguiente=nodo;
  this.cola=this.cola.siguiente;
 }

 public void borrarNodo(Nodo nodo){
  nodo.siguiente=null;
 }

 public Nodo buscarNodo(int valor){
  Nodo nodoActual=this.cabeza;
  while (nodoActual!=null){
    if (nodoActual.valor == valor){
      return nodoActual;
    }
    nodoActual=nodoActual.siguiente;
  }
  return null;
 }


 public void borrarNodoPorValor(int valor){
  Nodo nodoBorrar = buscarNodo(valor);
  if (nodoBorrar!=null){
    nodoBorrar.siguiente=null;
  }
 }
}