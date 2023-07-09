public class Nodo{
  protected int valor;
  protected Nodo siguiente;
  protected Nodo anterior;
  public Nodo(){}

  public Nodo(int x){
    this.valor=x;
    this.siguiente=null;
    this.anterior=null;
  }
  
  public Nodo(int x, Nodo siguiente){
    this.valor=x;
    this.siguiente=siguiente;
    this.anterior=null;
  }

  public void setSiguiente(Nodo nodo){
    this.siguiente=nodo;
  }

  public void setAnterior(Nodo nodo){
    this.anterior=nodo;
  }

  public void setValor(int valor){
    this.valor=valor;
  }
}