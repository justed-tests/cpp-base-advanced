#include <iostream>

using namespace std;

class Account
{
  public:
    Account(double bal) 
    {
      if (bal < 0) bal = 0;
      balance = bal;
    }

    void credit(double amount) 
    {
      balance += amount;
    }

    void debit(double amount) 
    {
      if (balance < amount) {
        cout <<  "Insufficient funds." << endl;
      } else {
        balance -= amount;
      }
    }

    double getBalance () {
      return balance;
    }

  protected:
    double balance;
};

class CheckingAccount : public Account
{
  public:
    CheckingAccount(double bal, double f)
      : Account(bal)
    {
      fee = f;
    }

    void debit(double amount)
    {
      if (balance > amount + fee) {
        balance -= amount + fee;
      } else {
        cout <<  "Insufficient funds." << endl;
      }
    }
  private:
  protected:
    double fee;
};

int main()
{
  CheckingAccount ac(100, 1);
  ac.debit(10);
  ac.credit(10);

  cout << ac.getBalance();
  return 0;
}
