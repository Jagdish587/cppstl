#include <iostream>
#include <deque>

using namespace std;


void dequecreation()
{
  std::deque<int> mydeque1 = {8,5,7,12,1,16,99,27};

  // deque traversal
  for (auto &it : mydeque1) {
    cout<<it<<" ";
  }

  cout<<endl;

  // unlike vector continous storage allocation may not be guaranteed
  for (auto &it : mydeque1) {
    cout<<&it<<"\n";
  }

  cout<<endl;

  cout<<"beign iterator = ";
  for (auto bit = mydeque1.begin(); bit!=mydeque1.end(); ++bit) {
    cout<<*bit<<" ";
  }

  cout<<endl;

  cout<<"end iterator = ";
  for (auto rbit = mydeque1.end(); rbit!= mydeque1.begin(); --rbit) {
    cout<<*rbit<<" ";
  }

  cout<<endl;

  cout<<"rbegin rend iterator = ";
  for ( auto rbeigin = mydeque1.rbegin(); rbeigin != mydeque1.rend(); ++rbeigin) {
    cout<<*rbeigin<<" ";
  }
  cout<<endl;


  // size of deque

  cout<<"size = "<<mydeque1.size()<<endl;
  cout<<"max size = "<<mydeque1.max_size()<<endl;
  cout<<"is empty deque = "<<mydeque1.empty()<<endl;

  cout<<"at usage = "<<mydeque1[2]<<endl;


}

void dequeAcessmodifiers()
{

  // assign , push_back, push_front, pop_back, pop_front ,
  // insert, erase, swap, clear, emplace , emplace_front, emplace_back
  std::deque<int> mydeque1 = {8,5,7,12,1,16,99,27};

  // deque traversal
  for (auto &it : mydeque1) {
    cout<<it<<" ";
  }

  cout<<endl;

  std::deque<int>::iterator myit = mydeque1.begin();
  std::advance(myit,3);

  mydeque1.insert(myit,54);

  // deque traversal
  for (auto &it : mydeque1) { // o/p: 8 5 7 54 12 1 16 99 27
    cout<<it<<" ";
  }

  cout<<endl;

  mydeque1.push_back(89);

  // deque traversal
  for (auto &it : mydeque1) { // o/p: 8 5 7 54 12 1 16 99 27 89
    cout<<it<<" ";
  }
  cout<<endl;

  mydeque1.push_front(66);
  for (auto &it : mydeque1) { // o/p: 66, 8 5 7 54 12 1 16 99 27 89
    cout<<it<<" ";
  }
  cout<<endl;

  mydeque1.pop_back();
  for (auto &it : mydeque1) { // o/p: 66, 8 5 7 54 12 1 16 99 27
    cout<<it<<" ";
  }
  cout<<endl;

  mydeque1.pop_front();
  for (auto &it : mydeque1) { // o/p: 8, 5, 7, 54, 12, 1, 16, 99, 27
    cout<<it<<" ";
  }
  cout<<endl;

  std::deque<int>::iterator it = mydeque1.begin();
  std::advance(it,4);
  mydeque1.emplace(it,43);
  for (auto &it : mydeque1) { // o/p: 8, 5, 7, 54, 43, 12, 1, 16, 99, 27
    cout<<it<<" ";
  }
  cout<<endl;

  mydeque1.emplace_front(23);
  for (auto &it : mydeque1) { // o/p: 23, 8, 5, 7, 54, 43, 12, 1, 16, 99, 27
    cout<<it<<" ";
  }
  cout<<endl;

  mydeque1.emplace_back(65);
  for (auto &it : mydeque1) { // o/p: 23, 8, 5, 7, 54, 43, 12, 1, 16, 99, 27, 65
    cout<<it<<" ";
  }
  cout<<endl;

  mydeque1.erase(it);
  for (auto &it : mydeque1) { // o/p: 23, 8, 5, 7, 54, 12, 1, 16, 99, 27, 65
    cout<<it<<" ";
  }
  cout<<endl;

  std::deque<int> mydeque2 = {22, 24, 66, 88, 99};
  mydeque1.swap(mydeque2);

  for (auto &it : mydeque1) { // o/p: 22, 24, 66, 88, 99
    cout<<it<<" ";
  }
  cout<<endl;

  for (auto &it : mydeque2) { // o/p: 23, 8, 5, 7, 54, 12, 1, 16, 99, 27, 65
    cout<<it<<" ";
  }
  cout<<endl;


  mydeque1.clear();
  mydeque2.clear();


  cout<<"mydeque1 size = "<<mydeque1.size()<<endl;
  cout<<"mydeque2 size = "<<mydeque2.size()<<endl;


}

int main()
{


  dequecreation();

  dequeAcessmodifiers();

  return 0;

}
