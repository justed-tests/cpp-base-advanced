#include <iostream>
#include <sstream>
#include <vector>

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

    ~Employee()
    {
    }

    string getName() { return name; }
    double getPay() { return pay; }

    void setPay(double newPay) { pay = newPay; }
    void setName(string newName) { name = newName; }

    double grossPay(int hours) { return pay * hours; }

    string virtual toString()
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
    }
    Manager(string empName, double  empPay, bool isSalaried) 
      : Employee {empName, empPay}
    {
      salaried = isSalaried;
    }

    ~Manager()
    {
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

    string virtual toString () override
    {
      stringstream stm;
      string sal = salaried ? "salaried" : "hourly";
      stm << name << ": " << pay << " " << sal;
      return stm.str();
    }
  private:
    bool salaried;
};

void smart(vector<Employee*> emps)
{
  for (auto emp : emps) {
    cout << emp->toString() << endl;
  }
}

int main ()
{
  auto e1 = new Employee("e1", 1);
  auto e2 = new Manager("e2", 2, false);
  
  vector<Employee*> emps;

  emps.push_back(e1);
  emps.push_back(e2);

  smart(emps); 

  vector<Employee> emps2;

  Employee e3("e3", 3);
  Manager e4("e4", 4, true);

  emps2.push_back(e3);
  emps2.push_back(e4);

  for (unsigned long i = 0; i < emps2.size(); i++) {
    cout << emps2[i].toString() << endl;
  }

  return 0;
}
