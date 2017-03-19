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
      cout << "Employee default constructor" << endl;
    }

    Employee(string empName, double empPay)
    {
      name = empName;
      pay = empPay;
      cout << "Employee explicit constructor" << endl;
    }

    ~Employee()
    {
      cout << "Employee destructor" << endl;
    }

    string getName() { return name; }
    double getPay() { return pay; }

    void setPay(double newPay) { pay = newPay; }
    void setName(string newName) { name = newName; }

    double grossPay(int hours) { return pay * hours; }

    string toString()
    {
      stringstream stm;
      stm << name << ": " << pay;
      return stm.str();
    }

  protected:
    string name;
    double pay;
};

class Manager : public Employee 
{
  public:
    Manager()
      : salaried(true)
    {
      cout << "manager default constructor" << endl;
    }
    Manager(string empName, double  empPay, bool isSalaried) 
      : Employee {empName, empPay}
    {
      cout << "manager explicit contructor" << endl;
      salaried = isSalaried;
    }

    ~Manager()
    {
      cout << "Manager destructor" << endl;
    }

    bool getSalaried () { return salaried; }
    void setSalaried (bool isSalaried) { salaried = isSalaried; }

    double grossPay (int hours)
    {
      if (salaried) {
        return pay;
      } else {
        return pay * hours;
      }
    }

    string toString () 
    {
      stringstream stm;
      string sal = salaried ? "salaried" : "hourly";
      stm << name << ": " << pay << " " << sal;
      return stm.str();
    }
  private:
    bool salaried;
};

int main ()
{
  //Employee emp("joshua", 99);
  
  Manager man;

  cout << man.toString() << endl;

  return 0;
}
