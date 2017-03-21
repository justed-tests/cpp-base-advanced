#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Animal
{
  public:
    virtual void talk () = 0;
};

class Dog : public Animal
{
  public:
    virtual void talk () override
    {
      cout << "wough wough!" << endl;
    }
};

class Cat : public Animal
{
  public:
    virtual void talk () override
    {
      cout << "meouwww!" << endl;
    }
};

int main ()
{
  vector<shared_ptr<Animal>> animals;

  animals.push_back(make_shared<Dog>());
  animals.push_back(make_shared<Cat>());

  for (auto animal : animals) animal->talk();
  return 0;
}
