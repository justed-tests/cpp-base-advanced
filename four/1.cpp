#include <iostream>

using namespace std;

int main ()
{
  char c;

  do {
    c = cin.get();
    cout.put(c);
  } while (c != '!');

  return 0;
}
