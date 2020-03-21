#include <iostream>
#include <queue>

using namespace std;


void queuecreation()
{
  // container adapters: stack , queue , priority_queue
  // priority_queue is adapter class , it is based on vector
  // stack and queue is based on dequeu

  std::queue<int> myqueue;
  myqueue.push(34);
  myqueue.push(64);
  myqueue.push(99);
  myqueue.push(56);

  cout<<"my queue creation = ";

  while (!myqueue.empty()) {
    cout<<myqueue.front()<<" ";
    myqueue.pop();
  }

  cout<<endl;

}

int main()
{

	queuecreation();

	return 0;
}
