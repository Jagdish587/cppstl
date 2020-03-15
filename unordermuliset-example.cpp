#include <iostream>
#include <unordered_set>

using namespace std;


void unorderedmultisetcreation()
{
  std::unordered_multiset<int> myonmultiset = {1,2,5,1,3,7,1};

 // same elemnts come comes beacuse of same bucket
  for (auto &mit  : myonmultiset) {
    cout<<mit<<" ";
  }
  cout<<endl;

  auto search = myonmultiset.find(7);

  if(search != myonmultiset.end()) {
    cout<<"foud = "<<*search<<endl;
  }

  cout<<"count of 1 = "<<myonmultiset.count(1)<<endl;

  cout<<"equal range = "<<endl;
  auto myrang = myonmultiset.equal_range(1);

  for (auto mit = myrang.first; mit != myrang.second; ++mit) {
    cout<<*mit<<" ";
  }
  cout<<endl;

}

int main()
{
	unorderedmultisetcreation();
}	
