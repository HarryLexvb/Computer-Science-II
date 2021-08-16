#include <iostream>
#include <limits>

using namespace std;

const int INFINITY = numeric_limits<int>::max();
const int ARRAY_SIZE = 10;

template <typename T>
struct nodo{
   T valor;
   nodo *next;

   nodo(T v, nodo *n = nullptr)
   {
      valor = v;
      next = n;
    }
};

void arraytolist(int* a, nodo<int>* &head){

    head = new nodo<int>(a[0]);
    nodo<int>* t = head;

    for(int i = 1; i < ARRAY_SIZE; i++) {
        t->next = new nodo<int>(a[i]);
        t = t->next;
    }
}

void printlista(nodo<int> *p) {
    cout<<"Head -> ";

    for(; p; p = p -> next)
        cout<<p->valor<<" -> ";

    cout<<"NULL"<<endl;
}

void mezcla(nodo<int>* &l1, nodo<int>* &l2, nodo<int>* &l3) {

    int primerElemento, segundoElemento;
    nodo<int>* temp;

    if(l1 != NULL || l2 != NULL) {
        primerElemento = l1 != NULL ? l1->valor : INFINITY;
        segundoElemento = l2 != NULL ? l2->valor : INFINITY;

        if(primerElemento < segundoElemento) {
                l3 = l1;
                l1 = l1->next;
        } else {
                l3 = l2;
                l2 = l2->next;
        }

        temp = l3;
    }

    while(l1 != NULL || l2 != NULL) {
            primerElemento = l1 != NULL ? l1->valor : INFINITY;
            segundoElemento = l2 != NULL ? l2->valor : INFINITY;

            if(primerElemento < segundoElemento) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }

            temp = temp->next;
    }
}

int main() {

    int a[ARRAY_SIZE] = {4,7,11,14,17,20,31,32,33,40};
    int b[ARRAY_SIZE] = {4,7,9,11,14,17,20,23,25,30};

    nodo<int> *lista1 = NULL, *lista2 = NULL, *lista3 = NULL;

    arraytolist(a,lista1);
    cout<<"Lista 1"<<endl;
    printlista(lista1);

    arraytolist(b,lista2);
    cout<<"Lista 2"<<endl;
    printlista(lista2);

    mezcla(lista1,lista2,lista3);
    cout<<"--------------------------"<<endl;
    cout<<"Lista 1"<<endl;
    printlista(lista1);
    cout<<"Lista 2"<<endl;
    printlista(lista2);
    cout<<"Lista 3"<<endl;
    printlista(lista3);
    return 0;
}
