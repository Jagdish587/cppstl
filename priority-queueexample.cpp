#include <iostream>
#include <queue>

using namespace std;

void priorityqueuecreation()
{
  // container adapters: stack , queue , priority_queue
  // priority_queue is adapter class , it is based on vector
  // stack and queue is based on dequeu
	
  std::priority_queue<int> mypqueue;

  mypqueue.push(30);
  mypqueue.push(45);
  mypqueue.push(84);
  mypqueue.push(34);

  cout<<"greater priority queue elemensts = ";

  while (!mypqueue.empty()) {
    cout<<mypqueue.top()<<" ";
    mypqueue.pop();
  }

  cout<<endl;

 // implement smaller

  std::priority_queue<int, vector<int>, greater<int> > mypqueue2;

  mypqueue2.push(30);
  mypqueue2.push(45);
  mypqueue2.push(84);
  mypqueue2.push(34);

  cout<<"smaller priority queue elemensts = ";

  while (!mypqueue2.empty()) {
    cout<<mypqueue2.top()<<" ";
    mypqueue2.pop();
  }
  
  cout<<endl;
}


int main()
{
 
	priorityqueuecreation();

	return 0;

}
