#include <iostream>
#include <sstream>

using namespace std;

class Employee
{
  public:
    Employee()
    {
      name = "";
      pay = 0;
    }

    Employee(string empName, double empPay)
    {
      name = empName;
      pay = empPay;
    }

    string getName() { return name; }
    double getPay() { return pay; }

    void setPay(double newPay) { pay = newPay; }
    void setName(string newName) { name = newName; }

    string toString()
    {
      stringstream stm;
      stm << name << ": " << pay;
      return stm.str();
    }

  private:
    string name;
    double pay;
};

class Manager : public Employee 
{
  public:
    Manager(string empName, double  empPay, bool isSalaried) 
      : Employee {empName, empPay}
    {
      salaried = isSalaried;
    }

    bool getSalaried () { return salaried; }
    void setSalaried (bool isSalaried) { salaried = isSalaried; }
  private:
    bool salaried;
};

int main ()
{
  Employee emp("joshua", 99);
  
  Manager man("don", 44, true);


  cout << man.toString();

  return 0;
}
