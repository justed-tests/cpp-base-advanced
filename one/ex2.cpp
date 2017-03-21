#include <iostream>
#include <memory>
#include <vector>

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

    virtual void display ()
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
    {
    }
    virtual void display ()
    {
      cout << "Trapezoid with sides" 
        << " " << side1
        << " " << side2
        << " " << side3
        << " " << side4
        << endl; 
    }
};

class Square : public Quadrilateral
{
  public:
    Square (double s)
      : Quadrilateral(s, s, s, s)
    {
    }
    virtual void display ()
    {
      cout << "Square with sides" 
        << " " << side1
        << " " << side2
        << " " << side3
        << " " << side4
        << endl; 
    }
};

int main ()
{
  vector<shared_ptr<Quadrilateral>> v;

  v.push_back(make_shared<Square>(1));
  v.push_back(make_shared<Quadrilateral>(1, 2, 3, 4));
  v.push_back(make_shared<Trapezoid>(4, 5, 6, 7));

  for (auto i : v) {
    i->display();
  }
}
