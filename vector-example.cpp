#include <iostream>
#include <vector>
using namespace std;

void myvectorinit()
{
  vector<int> g1;

  for (int i = 1; i <= 10; i++)
    g1.push_back(i);


  // vector elements are contigous
  cout << "Output of begin and end: "<<endl;
  for (auto i = 0 ; i <=10 ; ++i)
    cout << &g1[i] <<endl;

   cout<<endl;

}


void myvectoriterator()
{
  vector<int> g1;

  for (int i = 1; i <= 10; i++)
    g1.push_back(i);

  cout << "\nOutput of begin and end: ";
  for (auto i = g1.begin(); i != g1.end(); ++i) {
    *i = *i + 5;
    cout << *i  << " ";
  }

  cout << "\nOutput of cbegin and cend: "; // constant iterator
  for (auto i = g1.cbegin(); i != g1.cend(); ++i)
    cout << *i << " ";

  cout << "\nOutput of rbegin and rend: ";
  for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
    cout << *ir << " ";

  cout << "\nOutput of crbegin and crend : "; // constant iterator
  for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
    cout << *ir << " ";


  cout<<endl;

}

void myvectoracessmodifier()
{
  vector<int> g1;

  for (int i = 1; i <= 10; i++)
    g1.push_back(i);

  cout << "\nOutput of push back ";
  for (auto i = g1.begin(); i != g1.end(); ++i) {
    cout << *i  << " ";
  }

  cout<<endl;

  g1.pop_back(); // removes last element

  cout << "\nOutput pop back ";
  for (auto i = g1.begin(); i != g1.end(); ++i) {
    cout << *i  << " ";
  }

  cout<<endl;

  // insert element after a postion , rest of elements are moved to right
  g1.insert(g1.begin() + 3,55);

  cout << "\nOutput of insert elemnets: ";
  for (auto i = g1.begin(); i != g1.end(); ++i) {
    cout << *i  << " ";
  }

  // insert vs emplace , emplace means in place

  g1.emplace(g1.begin(), 77);

  cout << "\nOutput of emplace : "; // constant iterator
  for (auto i = g1.cbegin(); i != g1.cend(); ++i)
    cout << *i << " ";

  cout<<endl;

  g1.emplace_back(121);

  cout << "\nOutput of emplace back: "; // constant iterator
  for (auto i = g1.cbegin(); i != g1.cend(); ++i)
    cout << *i << " ";

  cout<<endl;


}
int main()
{

  myvectorinit();
  myvectoriterator();
  myvectoracessmodifier();

  return 0;

}

