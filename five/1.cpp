#include <iostream>
#include <list>

using namespace std;

void display (list<int> l)
{
  list<int>::iterator i = l.begin();

  while (i != l.end()) {
    cout << *i << endl;
    i++;
  }

  cout << "---------------" << endl;
}

void insertMax(list<int> &l, int value)
{
  l.sort();
  if (l.back() < value) {
    l.push_back(value);
  }
}


int main ()
{
  list<int> ll;

  cout << ll.front() << endl;
  cout << "***" << endl;

  list<int> l = {7, 1, 2 ,3};

  display(l);
  insertMax(l, 9);
  display(l);
  return 0;
}
