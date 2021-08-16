#include<iostream>
using namespace std;

int transpose(int (*matrix)[3], int row, int col){
    int i, j;
    int trans[3][3];
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            trans[j][i] = (*matrix)[j];
        }
        matrix++;
    }
    cout<<"\nMatriz transpuesta:\n";
    for(i = 0; i < col; i++){
        for(j = 0; j < row; j++){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){


    int A[3][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9}};

    transpose(A, 3, 3);
}