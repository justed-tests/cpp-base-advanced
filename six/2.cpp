#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main ()
{
  multimap<string, string> m;

  m.insert(pair<string, string>("one", "one 1 value"));
  m.insert(pair<string, string>("error spirit", "two 1 value"));
  m.insert(pair<string, string>("one", "one 2 value"));
  m.insert(pair<string, string>("one", "one 2 value"));
  m.insert(pair<string, string>("two", "two 1 value"));

  auto it = m.find("one");
  auto end = m.upper_bound("one");

  for (; it != end; it++) {
    cout << it->first << ':' << it->second << endl;
  }


 return 0;
}
