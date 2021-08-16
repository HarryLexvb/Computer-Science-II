#include <iostream>

using namespace std;

template <class T>
struct nodo
{
    T dato;
    nodo<T> *next;

    nodo(T d, nodo<T> *n = nullptr)
    {
        dato = d;
        next = n;
    }
};

template<class T>
class pila
{
public:
    nodo<T> *top =nullptr;

    void push(T elem)
    {
        top = new nodo<T>(elem, top);
    }

    T pop()
    {
        T tmp = top->dato;
        nodo<T>* tmpTop = top;
        top = top->next;
        delete tmpTop;
        return tmp;
    }

    ~pila()
    { 
        while (top)
            pop();
    }
};


int main()
{
    int valores[5] = {3,8,25,37,1};
    pila<int> st;

    for (int i = 0; i < 5; i++)
        st.push(valores[i]);

    while (st.top)
        cout << st.pop() << endl;
    
    return 0;
}