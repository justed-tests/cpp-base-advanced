#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack
{
  public:
    Stack ()
      : top(-1)
    {
    }

    void push (T data)
    {
      ++top;
      datastore[top] = data;
    }

    T pop ()
    {
      int index = top--;
      T value = datastore[index];
      datastore[index] = 0;
      return value;
    }

    T peek ()
    {
      return  datastore[top];
    }
  private:
    T datastore[100];
    int top;
};

template<>
class Stack<string>
{
  public:
    Stack ()
      : top(-1)
    {
    }

    void push (string data)
    {
      ++top;
      datastore[top] = data;
    }

    string pop ()
    {
      int index = top--;
      string value = datastore[index];
      datastore[index] = "";
      return value;
    }

    string peek ()
    {
      return  datastore[top];
    }
  private:
    string datastore[100];
    int top;
};

int main ()
{
  Stack<string> a;
  a.push("first string");
  a.push("second string");

  Stack<int> b;
  b.push(1);
  b.push(2);

  cout << a.pop() << endl;
  cout << a.pop() << endl;

  cout << b.pop() << endl;
  cout << b.pop() << endl;

  return 0;
}
