// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

public class Palindrome {
    public boolean isPalindrome(Nodo cabeza){
      if (cabeza==null){
        return true;
      }
      Nodo comienzoSegundaMitad=reversarLista(cabeza);
      boolean esPalindromo=true;
      Nodo p1=cabeza;
      Nodo p2=comienzoSegundaMitad;
      while(esPalindromo && p2!=null){
        if(p1.valor!=p2.valor){
          esPalindromo=false;
          break;
        }
        p1=p1.siguiente;
        p2=p2.siguiente;
      }
      comienzoSegundaMitad=reversarLista(comienzoSegundaMitad);
      return esPalindromo;
    }

    public Nodo encontrarMitad(Nodo cabeza){
      Nodo rapido=cabeza;
      Nodo lento=cabeza;
      while(rapido.siguiente != null && rapido.siguiente.siguiente!=null){
        rapido=rapido.siguiente.siguiente;
        lento=lento.siguiente;
      }
      return lento;
    }

    public Nodo reversarLista(Nodo cabeza){
      Nodo anterior=null;
      Nodo actual=cabeza;
      while (actual!=null){
        Nodo siguienteTemporal=actual.siguiente;
        actual.siguiente=anterior;
        anterior=actual;
        actual=siguienteTemporal;
      }
      return actual;
    }
}