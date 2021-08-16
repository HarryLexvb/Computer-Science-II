#include <iostream>

using namespace std;

struct par
{
    bool operator()(int a)
    {
        return a % 2 == 0;
    }
};

struct impar
{
    bool operator()(int a)
    {
        return a % 2 != 0;
    }
};

struct nodo
{
    int valor;
    nodo* next;
    nodo(int v, nodo* n = nullptr)
    {
        valor = v; next = n;
    }
};

void crear(int* p, nodo*& lista)
{
    lista = new nodo(*p);
    p++;
    for (nodo* n = lista; *p > 0; p++, n = n->next)
        n->next = new nodo(*p);

}

void destruir(nodo*& lista)
{
    nodo* tmp;
    while (lista)
    {
        tmp = lista;
        lista = lista->next;
        delete tmp;
    }
}

void print(nodo* lista)
{
    cout << "lista -> ";
    for (; lista; lista = lista->next)
        cout << lista->valor << " -> ";
    cout << "NULL" << endl;
}

template <typename T>
void separa(nodo*& p, nodo*& q, nodo*& r, T cond)
{
    q = r = nullptr;
    nodo* it = p, *current, *hQ = q, *hR = r;
    while(it){
      current = it;
      it = it->next;
      current->next = nullptr;
      if(cond(current->valor)){
        q = current;
        std::cout << "q:" << q->valor << std::endl;
        q = q->next;
      }
      else{
        r = current;
        std::cout << "r:" << r->valor << std::endl;
        r = r->next;
      }
    }
    q = hQ;
    r = hR;
    p = nullptr;
}

int main() {
    int a[15] = { 1,2,3,5,13,15,17,25,32,33,40,41,43,44,-1 };

    nodo* l1, * l2 =nullptr, * l3 = nullptr;

    crear(a, l1);

    cout << "antes de la separacion par" << endl;
    print(l1);
    print(l2);
    print(l3);

    separa(l1, l2, l3,par());

    cout << "despues de separacion par" << endl;
    print(l1);
    print(l2);
    print(l3);
    
    destruir(l1);
    destruir(l2);
    destruir(l3);

    crear(a, l1);

    cout << "antes de la separacion impar" << endl;
    print(l1);
    print(l2);
    print(l3);

    separa(l1, l2, l3, impar());

    cout << "despues de separacion impar" << endl;
    print(l1);
    print(l2);
    print(l3);

    destruir(l1);
    destruir(l2);
    destruir(l3);

}