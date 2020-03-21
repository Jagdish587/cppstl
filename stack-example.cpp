#include <iostream>
#include <stack>
using namespace std;

void stackcreation()
{
  // container adapters: stack , queue , priority_queue
  // priority_queue is adapter class , it is based on vector
  // stack and queue is based on dequeu

  std::stack<int> mystack;

  mystack.push(20);
  mystack.push(44);
  mystack.push(74);
  mystack.push(96);

  cout<<"stack elements = ";
  while (!mystack.empty()) {
     cout<<mystack.top()<<" ";
     mystack.pop();
  }

  cout<<endl;

}

int main()
{
 
	stackcreation();

	return 0;

}
