#include <iostream>

#include <set>
#include <functional>

using namespace std;


class Person {
 public:
  int age;
  string name;

  bool operator < (const Person& rhs) const {
    return  age < rhs.age ;
  }

};

void mysetcreation()
{
  // In Set , Elements are stored in sorted order
  // Implemented using Red Black Tree
  std::set< int,std::greater<int> > myset = {5,8,7,6,4,8,11,2,6};

  cout<<"set value ";
  for(auto &nit : myset) {
    cout<<nit<<" ";
  }

  cout<<endl;


  std::set<Person> myperson = {
                               {25, "Jagdish"},
                               {25, "Tirumala" }
                              } ;

  cout<<"Person values = \n";

  for(auto &pit : myperson) {
    cout<<pit.age<<" "<<pit.name<<endl;
  }

  cout<<endl;




  cout<<endl;


}

int main()
{

 mysetcreation();

  return 0;

}

