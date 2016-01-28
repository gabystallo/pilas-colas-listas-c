#include <stdio.h>

struct nodo {
  int val;
  struct nodo * sig;
};

int init(struct nodo ** estructura) {

  *estructura = (struct nodo *)0;

  return 0;
}

//es común para pilas y para colas

int push(struct nodo ** pila, struct nodo * nodo) {

  (*nodo).sig=*pila;
  *pila=nodo;

  return 0;
}

// pilas //

struct nodo * pop(struct nodo ** pila) {

  struct nodo * aux;
  aux = *pila;
  if(aux)
    *pila = (*aux).sig;

  return aux;
}

// colas //

struct nodo * unqueue(struct nodo ** cola) {

  struct nodo * aux;
  struct nodo ** apuntador;

  apuntador = cola; //apunta a quien apunta al siguiente nodo (o el root, o el sig del nodo anterior)

  while(*apuntador && (**apuntador).sig)
    apuntador=&(**apuntador).sig;

  if(aux = *apuntador) //si la cola estuviera vacía la línea siguiente daría error
    *apuntador = (**apuntador).sig;

  return aux;
}



int main() {

  struct nodo * pila;
  struct nodo * cola;
  struct nodo nodo1;
  struct nodo nodo2;
  struct nodo nodo3;

  struct nodo * aux;

  nodo1.val=1;
  nodo2.val=2;
  nodo3.val=3;

  //pila
  printf("-- pila --\n");
  init(&pila);
  push(&pila, &nodo1);
  push(&pila, &nodo2);
  push(&pila, &nodo3);

  while(aux=pop(&pila))
    printf("%i\n",(*aux).val);

  //cola
  printf("-- cola --\n");
  init(&cola);
  push(&cola, &nodo1);
  push(&cola, &nodo2);
  push(&cola, &nodo3);

  while(aux=unqueue(&cola))
    printf("%i\n",(*aux).val);

  return 0;
}
