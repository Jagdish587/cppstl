
#include <iostream>
#include <vector>
#include <list>

using namespace std;


bool is_even (const int& value) { return (value%2) ; }

void listcreation()
{
  list<int> mylist;

  for(int i = 0 ;i <= 20 ;i++)
    mylist.push_back(i);

/*list elements are not contigious */ 
  for (auto const &v : mylist)
    std::cout << &v <<endl;

  cout<<endl;

}

void listoperations()
{
	list<int> mylist;

  for(int i = 0 ;i <= 20 ;i++)
    mylist.push_back(i);

  for (auto const &v : mylist)
    std::cout << v <<" ";

  cout<<endl;

  // reverse a list
  mylist.reverse();

  for (auto const &v : mylist)
    std::cout << v <<" ";

  cout<<endl;


  std::list<int> mylist2 = {23,44,55,44,76,89};

  for (auto const &v : mylist2)
    std::cout << v <<" ";

  cout<<endl;

  mylist2.sort();

  for (auto const &v : mylist2)
    std::cout << v <<" ";

  cout<<endl;

  mylist2.unique();

  for (auto const &v : mylist2)
    std::cout << v <<" ";

  cout<<endl;

  std::list<int> mylist3 =  {23,44,55,44,76,89,76,89};

  mylist3.remove(76);


  for (auto const &v : mylist3)
    std::cout << v <<" ";

  cout<<endl;

  std::list<int> mylist4 =  {1,5,6,23,44,55,44,76,89,76,89};

  mylist4.remove_if(is_even);


  for (auto const &v : mylist4)
    std::cout << v <<" ";

  cout<<endl;

  // splice copy elements from one list to another
  std::list<int> mylist5 ;
  std::list<int>::iterator nit = mylist4.begin();

  std::advance(nit,2);

  mylist5.splice(mylist5.begin(),mylist4,nit,mylist4.end());

  cout<<"losit 5 "<<endl;

  for (auto const &v : mylist5)
    std::cout << v <<" ";

  cout<<endl;
	
}	
	
	

void listmodifiers()
{
  // assign , emplace_front, push_front, pop_front, emplace_back,
  // push_back, pop_back, emplace, insert, erase, swap, resize , clear


  // assign replaces values in list and assign new values
   std::list<int> mylist4 =  {1,5,6,23,44,55,44,76,89,76,89};

   for(auto &it : mylist4)
     cout<<it<<" ";

   cout<<endl;

   std::list<int> mylist5 =  {1,5,6,23,44,55};


   mylist4.assign(mylist5.begin(),mylist5.end());

   for(auto &it : mylist4) //o/p: 1,5,6,23,44,55
     cout<<it<<" ";

   cout<<endl;

  // emplace_front = Construt and inserts new elements at the beggining

   mylist4.emplace_front(23);
   mylist4.emplace_front(34);
   mylist4.emplace_front(58);

   for(auto &it : mylist4) //o/p: 58, 34, 23, 1, 5, 6, 23, 44, 55
     cout<<it<<" ";

   cout<<endl;

  // push_front = insert element at the beggining
   mylist4.push_front(13);
   mylist4.push_front(24);
   mylist4.push_front(78);

   for(auto &it : mylist4) //o/p: 78, 24, 13, 58, 34, 23, 1, 5, 6, 23, 44, 55
     cout<<it<<" ";

   cout<<endl;

  // pop_front = delete first element
   mylist4.pop_front();
   mylist4.pop_front();
   mylist4.pop_front();

   for(auto &it : mylist4) //o/p: 58, 34, 23, 1, 5, 6, 23, 44, 55
     cout<<it<<" ";

   cout<<endl;

   // emplace_back Constructs and add elemnets at the end
   mylist4.emplace_back(26);
   mylist4.emplace_back(34);
   mylist4.emplace_back(44);

   for(auto &it : mylist4) //o/p: 58, 34, 23, 1, 5, 6, 23, 44, 55, 26, 34, 44
     cout<<it<<" ";

   cout<<endl;

  // push_back , add elements at the end
   mylist4.push_back(72);
   mylist4.push_back(89);
   mylist4.push_back(101);

   for(auto &it : mylist4) //o/p: 58, 34, 23, 1, 5, 6, 23, 44, 55, 26, 34, 44, 72, 89, 101
     cout<<it<<" ";

   cout<<endl;

  // pop_back , delete last elemenets
   mylist4.pop_back();
   mylist4.pop_back();
   mylist4.pop_back();

   for(auto &it : mylist4) //o/p: 58, 34, 23, 1, 5, 6, 23, 44, 55, 26, 34, 44
     cout<<it<<" ";

   cout<<endl;

  // emplace Construct and insert element after pos , othere elemenets are adjusted
   std::list<int>::iterator pnit = mylist4.begin();
   std::advance(pnit, 3);
   mylist4.emplace(pnit, 88);

   for(auto &it : mylist4) //o/p: 58, 34, 23, 88 , 1, 5, 6, 23, 44, 55, 26, 34
     cout<<it<<" ";

   cout<<endl;

   // erase : Removes the element after pos
   mylist4.erase(pnit);

   for(auto &it : mylist4) //o/p: 58, 34, 23, 88 , 5, 6, 23, 44, 55, 26, 34
     cout<<it<<" ";

   cout<<endl;

   // swap contents of list with another list
   std::list<int> mylist6 = {22,34,56,87,92,101};

   mylist4.swap(mylist6);

   for(auto &it : mylist4) //o/p: 22, 34, 56, 87 , 92, 101
     cout<<it<<" ";

   cout<<endl;

   for(auto &it : mylist6) //o/p: 58, 34, 23, 88 , 5, 6, 23, 44, 55, 26, 34
     cout<<it<<" ";

   cout<<endl;


   cout<<"list size = "<<mylist4.size()<<endl; // o/p : 6

   // resize  , resizes the list
   mylist4.resize(3);

   for(auto &it : mylist4) //o/p: 22, 34, 56
     cout<<it<<" ";

   cout<<endl;

  // clear : clear the connets of list
   mylist4.clear();

  cout<<"list size = "<<mylist4.size()<<endl; // o/p : 0

  cout<<endl;


}


int main()
{


 listcreation();
 listoperations();
 listmodifiers();
	
 

  return 0;

}
