#include <stdio.h>

struct nodo {
  int val;
  struct nodo * sig;
};

int init(struct nodo ** estructura) {

  *estructura = (struct nodo *)0;

  return 0;
}


int push(struct nodo ** pila, struct nodo * nodo) {

  (*nodo).sig=*pila;
  *pila=nodo;

  return 0;
}

struct nodo * pop(struct nodo ** pila) {

  struct nodo * aux;
  aux = *pila;
  if(aux)
    *pila = (*aux).sig;

  return aux;
}


int main() {

  struct nodo * pila;
  struct nodo nodo1;
  struct nodo nodo2;
  struct nodo nodo3;

  struct nodo * aux;

  init(&pila);

  nodo1.val=1;
  nodo2.val=2;
  nodo3.val=3;

  push(&pila, &nodo1);
  push(&pila, &nodo2);
  push(&pila, &nodo3);

  aux=pop(&pila);
  printf("%i\n",(*aux).val);
  aux=pop(&pila);
  printf("%i\n",(*aux).val);
  aux=pop(&pila);
  printf("%i\n",(*aux).val);

  return 0;
}
