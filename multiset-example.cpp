#include <iostream>
#include <set>

using namespace std;


struct MyPerson {
  int age;
  string name;

  bool operator < (const MyPerson& rhs) const {
    return age < rhs.age;
  }

  bool operator > (const MyPerson &rhs) const {
    return age > rhs.age;
  }

};


void  multisetcreation()
{

  // MultiSet constainsg only keys but with duplicates
  // for user defined data types , you need to provide comparator fucntions
  std::multiset<MyPerson> mymuliset = { {25,"Jagaadish"}, {28,"Tirumala"} , {25,"Jagadish"}, };

  cout<<"multi set values : \n";
  for (auto &it : mymuliset) {
    cout<<it.age<<" "<<it.name<<endl;
  }
  cout<<endl;


}

int main()
{
	multisetcreation();
}
