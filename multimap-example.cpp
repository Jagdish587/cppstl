#include <iostream>
#include <map>
using namespace std;



void mymultimapcreation()
{
  // Multi Map Creation , it can have duplicate keys
  // Here elements are sorted based on keys
  multimap<char, int, greater<char> > mymultimap;

 // insert
  mymultimap.insert(make_pair('a',23));
  mymultimap.insert(make_pair('a',33));
  mymultimap.insert(make_pair('a',43));
  mymultimap.insert(make_pair('b',56));
  mymultimap.insert(make_pair('c',81));
  mymultimap.insert(make_pair('a',91));

  cout<<"multimap values \n ";
  for (auto &myit : mymultimap) {
    cout<<myit.first<<" "<<myit.second<<endl;
  }

  cout<<endl;

  // emplace
  cout<<"emplace example \n";
  mymultimap.emplace('c',97);
  mymultimap.emplace('d',4);

  for (auto &myit : mymultimap) {
    cout<<myit.first<<" "<<myit.second<<endl;
  }

  cout<<endl;


  // find : it can return iterator to anything that finds 'a'
  auto fit = mymultimap.find('a');
  if(fit!=mymultimap.end())
    cout<<"first value = "<<fit->first<<" second value = "<<fit->second<<endl;

  //count : returns count elemenst with sepcific key
  cout<<"no of occurences a = "<<mymultimap.count('a')<<endl;

  // equal_range : returns range of elements matching a given key
  cout<<"equal ranges of 'a' = "<<endl;
  auto eqrang  = mymultimap.equal_range('a');
  for (auto it = eqrang.first ;it!= eqrang.second; ++it) {
    cout<<it->first<<" "<<it->second<<endl;
  }
  cout<<endl;

  // lower_bound : returns an iterator to the first element not less than the given key
  auto loit = mymultimap.lower_bound('a');
  cout<<"lower bound  "<<loit->first<<" "<<loit->second<<endl;

  // upper_bound : returns an iterator to the first element greater than the given key
  auto upit = mymultimap.upper_bound('a');
  cout<<"upper bound =  "<<upit->first<<" "<<upit->second<<endl;

}

int main()
{
	mymultimapcreation();
}

