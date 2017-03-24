#include <iostream>
#include <map>
#include <string>

using namespace std;

int main ()
{
  map<string, int> m;

  m["one"] = 1;

  cout << m["one"] << endl;
  cout << m["unexesting"] << endl;
  return 0;
}
