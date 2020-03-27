#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};


void createNode(Node** root,int data)
{
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = nullptr;
  newNode->right = nullptr;
  *root = newNode;
}

void levelorder(Node* root)
{
  if(root == nullptr)
    return;

  std::queue<Node*> myqueue;

  myqueue.push(root);

  while(!myqueue.empty()) {
    Node *front  = myqueue.front();
    cout<<front->data<<" ";

    if(front->left)
      myqueue.push(front->left);

    if(front->right)
      myqueue.push(front->right);

     myqueue.pop();
  }

  cout<<endl;

}


int main()
{
  Node *root = nullptr;

  createNode(&root, 1);
  createNode(&root->left, 2);
  createNode(&root->right, 3);
  createNode(&root->left->left, 4);
  createNode(&root->left->right, 5);
  createNode(&root->right->left, 6);
  createNode(&root->right->right, 7);

  levelorder(root);


}

