#include <iostream>

using namespace std;

 struct ParXY
{ 

  int x;
  int y;
  ParXY(int a, int b): x(a), y(b) {};
};

class Pendiente
{
  ParXY Origen;

  public:
    Pendiente(const ParXY& origin): Origen(origin){}

    int operator()(const ParXY& point){
      return (point.y - Origen.y) / (point.x - Origen.x);
    }
};

template<class O,class T, int a, int b>
class Calcular
{
  O op = O(T(a,b));

  public:
    void operator()(T* begin, T* end){
      for (T* it = begin; it <= end; ++it){
        std::cout << op(*it) << std::endl;
      }
    }

};

int main()
{
  ParXY xy[6] = { ParXY(3,3),  ParXY(-1,3), ParXY(3,9),  ParXY(-3,-9), ParXY(8,-15), ParXY(4,9) };

  Calcular<Pendiente,ParXY,1,1> Calc;
  
  Calc(&xy[0],&xy[5]);

}