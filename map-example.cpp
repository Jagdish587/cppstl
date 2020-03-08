#include <iostream>
#include <map>

using namespace std;


void  mapcreation()
{
  // Maps are assosicative containers
  // In Map Elements are sorted based on key
  // They are much more like Balanced Tree like AVL and Red Black Tree

  // BY default maps are sorted in Ascending Order
  std::map<int,string> mymap;

  mymap[5] = "Jagdish";
  mymap[8] = "I am ";
  mymap[7] = "Best";
  mymap[1] = "hello";
  mymap[11] = "this is good";

  for (auto &it : mymap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  cout<<endl;

  // Here elements are sorted in Descending Order
  std::map<int,string, greater<int> > mymap2;

  mymap2[5] = "Jagdish";
  mymap2[8] = "I am ";
  mymap2[7] = "Best";
  mymap2[1] = "hello";
  mymap2[11] = "this is good";

  for (auto &it : mymap2) {
    cout<<it.first<<" "<<it.second<<endl;
  }

  cout<<"size of mymap = "<<mymap.size()<<endl;
  cout<<"size of mymap2 = "<<mymap2.size()<<endl;

}

void mapmodifiers()
{
  // map modifers : insert, erase, swap, clear, emplace, emplace_hint
  // In map you can have duplicate keys , if you go by first approach
  // latest value is picked and by second approach it will take original value

  std::map<int,string> mymap;

  mymap[5] = "Jagdish";
  mymap[8] = "I am ";
  mymap[7] = "Best";
  mymap[1] = "hello";
  mymap[11] = "this is good";
  mymap[7] = "7 latest"; // this will be taken

  // insert example
  for (auto &it : mymap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  cout<<endl;

  mymap.insert(pair<int, string> (22,"i am twernty two"));
  mymap.insert(pair<int, string> (6,"six")); // this is taken
  mymap.insert(pair<int, string> (44,"fouer four"));
  mymap.insert(pair<int, string> (6,"six second time")); // it will not be taken


  for (auto &it : mymap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  cout<<endl;

  // emplace example
  mymap.emplace(12,"tweleve emplace");
  mymap.emplace(9,"nine emplace ");
  mymap.emplace(7,"seven from emplace "); // this is not taken

  for (auto &it : mymap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  cout<<endl;

  auto mit = mymap.end();

  // emlpace_hint , it is justa hint
   mymap.emplace_hint(mit,37,"tweleve emplace hint");
   for (auto &it : mymap) {
     cout<<it.first<<" "<<it.second<<endl;
   }
   cout<<endl;

   //erase
   mymap.erase(44); // 44 key is erased
   for (auto &it : mymap) {
     cout<<it.first<<" "<<it.second<<endl;
   }
   cout<<endl;

}

void mapoperations()
{

  std::map<int,string> mymap;

  mymap[5] = "Jagdish";
  mymap[8] = "I am ";
  mymap[7] = "Best";
  mymap[1] = "hello";
  mymap[11] = "this is good";
  mymap[7] = "7 latest"; // this will be taken

  // insert example
  for (auto &it : mymap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  cout<<endl;


  // find , returns iterator to element , else if no match found , returns map::end
  auto fit = mymap.find(5);

  if(fit != mymap.end()) {
    cout<<fit->first<<" "<<fit->second<<endl;
  } else {
    cout<<"no match found "<<endl;
  }

  auto sfit = mymap.find(15);

  if(sfit != mymap.end()) {
    cout<<sfit->first<<" "<<sfit->second<<endl;
  } else {
    cout<<"no match found "<<endl;
  }

  // count : count elements with specific key
  if(mymap.count(7) > 0)  {
    cout<<"key is present in map "<<endl;
  } else {
    cout<<"no key found "<<endl;
  }

  if(mymap.count(77) > 0)  {
    cout<<"key is present in map "<<endl;
  } else {
    cout<<"no key found "<<endl;
  }

 


}

int main()
{



 mapcreation();
 mapmodifiers();

 mapoperations();

  return 0;

}
