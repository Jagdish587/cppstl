#include <iostream>
#include <vector>

using namespace std;

struct Foo
{
  int myint ;
  double mydouble;

  Foo(int n, double x) {
    cout<<"constructor called "<<this<<endl;
    myint = n;
    mydouble = x;
  }

  Foo(const Foo& rhs ) {
    cout<<"copy constructor called "<<this<<endl;
    myint = rhs.myint;
    mydouble = rhs.mydouble;
  }

  void display() {
    cout<<"in Display Foo int = "<<myint<<" my double = "<<mydouble<<endl;
  }

};


int main()
{
	cout<<"********emplace example start ********"<<endl;

  	std::vector<Foo> v;

	v.emplace(v.begin(), 42, 3.1);
	v.insert(v.begin() + 1, Foo(24, 5.1));


    for(auto &it : v) {
        it.display();
    }

    cout<<"********emplace example end ********"<<endl;
	
    return 0;
}
