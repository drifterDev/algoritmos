// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct Node{
  int value;
  Node* next;
  Node* prev;
};

struct Lista{
  Node* head;
  Node* tail;
  int size;
};

Lista* constructor(){
  Lista* lista=new Lista;
  lista->head=nullptr;
  lista->tail=nullptr;
  lista->size=0;
  return lista;
}

bool hasCycle(Lista* lista){
  Node* slow=lista->head;
  Node* fast=lista->head;
  while(fast!=nullptr && fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)return true;
  }
  return false;
}