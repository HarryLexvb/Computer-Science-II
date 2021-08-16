#include <iostream>   
#include <fstream>    
#include <string>    
#include <cstring>
using namespace std; 

const double  pi = 3.14; 

double areaCirc(double a, double b){
  return (pi*(a*a));
}

double areaRect(double a, double b){
  return (a*b);
}

double areaTrian(double a, double b){
  return ((a*b)/2);
}


typedef double (*PF)(double, double);
int main()
{
  int parm[2] = {10,15}; 
  double(*pf[3])(double, double) = {areaCirc, areaRect, areaTrian};
  double(*(*ppff))(double, double) = pf; 
  PF puntFun[3] = {areaCirc, areaRect, areaTrian};
  PF *ppf = puntFun; 

  for (int i=0; i<3; i++)
   cout<<"area "<<i+1<<": "<<pf[i](parm[0], parm[1])<<endl;
}
