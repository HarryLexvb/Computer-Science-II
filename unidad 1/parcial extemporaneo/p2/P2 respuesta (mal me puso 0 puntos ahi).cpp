#include <iostream>

using namespace std;

void mezclar(int *a, int *b,int *c, int max)
{
  int *p = a;
  int * q = b;
  int i=0;
  int x[10]={1,2,3,4,5,6,7,8,9,10};
  while( (p<a+max)&&(q<b+max)){
      if (*p==x[i]){
          *c=*p;
      }
      while(q<b+max){
            if (*q==x[i]){
                *c=*q;
            }
        }
    
      i++;
    }
    
}


int main() {
  int A[5] = {1,2,5,8,9};
  int B[5] = {3,4,6,7,10};

  int C[10];

  cout<<"Array A"<<endl;
  for(int i=0; i<5;i++)
    cout<<A[i]<<" ";

  cout<<endl<<"Array B"<<endl;
  for(int i=0; i<5;i++)
    cout<<B[i]<<" ";

  mezclar(A,B,C,5);
  cout<<endl<<"Array C"<<endl;
  for(int i=0; i<10;i++)
    cout<<C[i]<<" ";
  
  return 0;
    
}