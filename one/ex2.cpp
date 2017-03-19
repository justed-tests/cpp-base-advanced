#include <iostream>

using namespace std;

class Quadrilateral
{
  public:
    Quadrilateral (double s1, double s2, double s3, double s4)
    {
      side1 = s1;
      side2 = s2;
      side3 = s3;
      side4 = s4;
    }

    void display ()
    {
      cout << "Quadrilateral with sides" 
        << " " << side1
        << " " << side2
        << " " << side3
        << " " << side4
        << endl; 
    }
  protected:
    double side1, side2, side3, side4;
};

class Trapezoid : public Quadrilateral
{
  public:
    Trapezoid (double s1, double s2, double s3, double s4)
      : Quadrilateral(s1, s2, s3, s4)
    { }
};

class Square : public Quadrilateral
{
  public:
    Square (double s)
      : Quadrilateral(s, s, s, s)
    { }
};

int main ()
{

}
