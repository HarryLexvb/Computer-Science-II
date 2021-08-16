
#include <iostream>
using namespace std;

int main(){
    int *arr;
    int dim;
    cout << "Ingresa el tamanyo del vector: ";cin >> dim;
    arr = new int[dim];
    //int n = sizeof(arr) / sizeof(arr[0]);
    //llenando el array
    for(int i = 0; i < dim; i++){
        //pv[i] = i * i;
        cout<<"ingrese los datos del array: "; cin >> arr[i];
    }
    cout<<"\ndesordenado:\n";
    //printArray(arr, n);
    for(int i = 0; i < dim; i++){
        printf("%d|", arr[i]);
    }

    bool swapped = true;
    //int start = 0;
    //int end = n - 1;
    int *start = arr;
    int *end = arr+dim-1;

    while (swapped) {
        swapped = false;
        for (int *t = start; t < end; ++t) {
            if(*t > *(t + 1)){
                swap(*t, *(t + 1) );
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int *t = end-1; t >= start; --t) {
            if(*t > *(t + 1)){
                swap(*t, *(t+1));
                swapped = true;
            }
        }
        ++start;
    }

    cout<<"\nordenado:\n";
    //printArray(arr, n);
    for (int i = 0; i < dim; i++)
        printf("%d|", arr[i]);
    printf("\n");

    delete[] arr;
}



