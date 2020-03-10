#include <iostream>
#include <unordered_map>

using namespace std;

void unordermapcreation()
{

  std::unordered_map<string,int> myunmap;

  myunmap["aaa"] = 1;
  myunmap["bbb"] = 2;
  myunmap["ccc"] = 3;
  myunmap["ddd"] = 4;
  myunmap["eee"] = 5;


  for(auto &it : myunmap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  cout<<endl;


  cout<<"bucket count = "<<myunmap.bucket_count()<<endl;
  cout<<"Max bucket count = "<<myunmap.max_bucket_count()<<endl;

  // number of elements in each bucket
  for(int i =0; i <myunmap.bucket_count();i++) {
    cout<<"bucket # = "<<i<<" has = "<<myunmap.bucket_size(i)<<endl;
  }


  // Note: if element is not present , it will add elements to unordered map with value 0
  cout<<"value at ddd = "<<myunmap["ddc"]<<endl;
  cout<<"value at ddg = "<<myunmap["ddg"]<<endl;

  for(auto &it : myunmap) {
    cout<<it.first<<" "<<it.second<<endl;
  }

  cout<<endl;

  for(auto &nit : myunmap) {
    cout<<"value = "<<nit.first<<" "<<nit.second;
    cout<<" is in bukcet "<<myunmap.bucket(nit.first)<<endl;
  }


}

void unordermapmodifiers()
{
  std::unordered_map<string,int> myunmap;

  myunmap["aaa"] = 1;
  myunmap["bbb"] = 2;
  myunmap["ccc"] = 3;
  myunmap["ddd"] = 4;
  myunmap["eee"] = 5;


  for(auto &it : myunmap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  cout<<endl;

  // insert
  myunmap.insert(std::pair<string,int>("fff",6));
  myunmap.insert(std::pair<string,int>("ggg",7));

  for(auto &it : myunmap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  cout<<endl;

  myunmap.emplace("hhh",8);
  myunmap.emplace("hhh",9);

  // emplace
  for(auto &it : myunmap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  cout<<endl;




}

int main()
{

  unordermapcreation();
  unordermapmodifiers();

  return 0;

}
