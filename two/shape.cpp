#include <iostream>

using namespace std;

class Shape
{
  public:
    virtual void setX (int xcor) = 0;
    virtual void setY (int ycor) = 0;

    virtual int getX () = 0;
    virtual int getY () = 0;

    virtual void draw () = 0;
};

class Circle : public Shape
{
  public:
    Circle (int xcor, int ycor, int r)
      : x(xcor),
        y(ycor),
        radius(r)
    {}

    virtual void setX (int xcor) override { x = xcor; };
    virtual void setY (int ycor) override { y = ycor; };
    void setRadius (int r) { radius = r; };

    virtual int getX () override { return x; };
    virtual int getY () override { return y; };
    int getRadius () { return radius; };

    virtual void draw () override
    {
      cout
        << "drawin cricle at "
        << x
        << ", "
        << y
        << " with radius of "
        << radius
        << endl;
    }
  private:
    int x, y, radius;
};

int main ()
{
  Circle c(1, 2, 3);

  c.draw();

  return 0;
}
