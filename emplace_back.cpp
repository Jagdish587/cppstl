#include <iostream>
#include <vector>

using namespace std;

struct Foo
{
  int myint ;

  Foo(int n) {
    cout<<"constructor called "<<this<<endl;
    myint = n;
  }

  Foo(const Foo& rhs ) {
    cout<<"copy constructor called "<<this<<endl;
    myint = rhs.myint;
  }

  void display() {
    cout<<"in Display Foo int = "<<myint<<endl;
  }

};


int main()
{
 cout<<"********emplace example start ********"<<endl;

  std::vector<Foo> v;

  v.emplace_back(85);

  for(auto &it : v) {
    it.display();
  }

  cout<<"********emplace example end ********"<<endl;


	return 0;
}
