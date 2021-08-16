//prueba de vectores
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void multiplicar(int *p);
int main()
{
  srand(time(NULL));
  int m[3][3][3];
  cout<<"\t\t\t\t3D matrix multiplier "<<endl;
  for(int capa=0; capa<3; capa++)
  {
    for(int fila=0; fila<3; fila++)
    {
      for(int c=0; c<3; c++)
      {
        m[capa][fila][c]=1 + rand()%5;
      }
    }
  }

  int *direccion = &m[0][0][0];
  multiplicar(direccion);

  cin.ignore();
  getchar();
  return 0;
}

void multiplicar(int *p)
{
 cout<<endl;
 cout<<endl;
          
  int tmp1[3][3], tmp2[3][3],xt=0, dc=0;
  for(int capa=0; capa<3; capa++)
  {
    for(int fila=0; fila<3; fila++)
    {
      for(int c=0; c<3; c++)
      {
        if(capa==0)
        {
          tmp1[fila][c]=*p;
        }
        if(capa==1)
        {
          tmp2[fila][c]=*p;
        }
        if(capa==2)
        {
            for(int y=0; y<3; y++)
            {
              xt=tmp1[fila][y] * tmp2[y][c];
              dc = dc + xt;
            }
          *p=dc;
          dc=0;
        }
        cout.width(3);
        cout<<*p<<" ";
        p++;
      }
      cout<<endl;
    }
    cout<<endl;
  }
}