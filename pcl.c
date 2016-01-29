#include <stdio.h>

// comunes para pilas, colas y listas

// una sola estructura en memoria, para los 3 casos:
// ROOT -> NODO(mas nuevo) -> NODO -> NODO -> NODO(mas viejo) -> NULL

// PROBAR CON ´make test´

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

// listas //

int agregar(struct nodo ** lista, struct nodo * nodo, unsigned int posicion) {

  unsigned int i;
  struct nodo ** apuntador;

  apuntador = lista;

  for(i=0;*apuntador && i<posicion;i++)
    apuntador=&(**apuntador).sig;

  (*nodo).sig=*apuntador;
  *apuntador=nodo;

  return 0;

}

struct nodo * quitar(struct nodo ** lista, unsigned int posicion) {

  unsigned int i;
  struct nodo ** apuntador;
  struct nodo * aux;

  apuntador = lista;

  for(i=0;*apuntador && (**apuntador).sig && i<posicion;i++)
    apuntador=&(**apuntador).sig;

  if(aux = *apuntador) //si la lista estuviera vacía, la línea siguiente daría error
    *apuntador = (**apuntador).sig;

  return aux;

}


//misceláneas de listas

int intercambiar(struct nodo ** lista, unsigned int p1, unsigned int p2) {

  //1 es el primer nodo del intercambio y 2 es el segundo nodo del intercambio

  unsigned int i;
  struct nodo ** apuntador1;
  struct nodo ** apuntador2;

  struct nodo * aux, aux2;

  apuntador1=apuntador2=lista;

  if(p1==p2) return 0;
  if(p2<p1) {
    i=p2;
    p2=p1;
    p1=i;
  }

  for(i=0;*apuntador1 && (**apuntador1).sig && i<p1;i++)
    apuntador1=&(**apuntador1).sig;
  for(i=0;*apuntador2 && (**apuntador2).sig && i<p2;i++)
    apuntador2=&(**apuntador2).sig;


  aux=(**apuntador1).sig;  //en caso que sean adyacentes, ahora aux es un puntero al 2

  (**apuntador1).sig=(**apuntador2).sig; //ojo, esto cambió a apuntador1
  if(p2>p1+1)
    (**apuntador2).sig=aux;
  else
    //si son adyacentes (aux es un backup del sig del 1, que ahora es lo unico que apunta al 2 (ya que *apuntador2, murió accidentalmente al reemplazar (**apuntador1).sig))
    (*aux).sig=*apuntador1;

  if(p2>p1+1) {
    //si no son adyacentes, es facil
    aux=*apuntador1;
    *apuntador1=*apuntador2;
    *apuntador2=aux;
  } else {
    //si son adyacentes, solo me falta corregir que el apuntador al 1, ahora apunte al 2
    *apuntador1=aux; //aux era un backup del puntero al 2
  }

  return 0;

}

int main() {

  struct nodo * pila;
  struct nodo * cola;
  struct nodo * lista;
  struct nodo nodo1;
  struct nodo nodo2;
  struct nodo nodo3;
  struct nodo nodo4;

  struct nodo * aux;

  nodo1.val=1;
  nodo2.val=2;
  nodo3.val=3;
  nodo4.val=4;

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

  //lista
  printf("-- lista --\n");
  init(&lista);
  agregar(&lista,&nodo1,0);
  agregar(&lista,&nodo3,1);
  agregar(&lista,&nodo2,1);

  aux=quitar(&lista,1);
  printf("%i\n",(*aux).val);
  while(aux=quitar(&lista,0))
    printf("%i\n",(*aux).val);

  //lista misc
  printf("-- lista misc --\n");
  init(&lista);
  agregar(&lista,&nodo1,0);
  agregar(&lista,&nodo3,1);
  agregar(&lista,&nodo2,1);
  agregar(&lista,&nodo4,3);
  intercambiar(&lista, 1, 3);
  while(aux=pop(&lista))
    printf("%i\n",(*aux).val);

  return 0;
}
