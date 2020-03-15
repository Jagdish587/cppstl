#include <iostream>
#include <map>
using namespace std;


void unorderedmulimap_creation()
{
  // Here key , value can come on any order
  // unorder map -> no duplicate keys
  // unorder multimap -> duplicate keys
  // Both uses hash table conepts , but additional count to keep track of duplicate elements

  std::unordered_multimap<char,int> myunmultimap;

  myunmultimap.insert(make_pair('a',22));
  myunmultimap.insert(make_pair('a',6));
  myunmultimap.insert(make_pair('a',54));
  myunmultimap.insert(make_pair('a',9));
  myunmultimap.insert(make_pair('b',42));
  myunmultimap.insert(make_pair('a',3));
  myunmultimap.insert(make_pair('b',36));

  for (auto &mit : myunmultimap) {
    cout<<mit.first<<" "<<mit.second<<endl;
  }
  cout<<endl;

}

int main()
{
	unorderedmulimap_creation();
}
