#include<iostream>
#include <queue>
using namespace std;

class Node {
public:
	int val;
	Node *left;
	Node *right;
	Node(int val){
		this->val=val;
		this->left=NULL;
		this->right=NULL;
	}
};
Node *buildTree(Node *root){
	cout<<"Enter Data"<<endl;
	int data;
	cin>>data;
	root=new Node(data);
	if(data==-1){
		return NULL;
	}
	cout<<"Enter data to left of "<<data<<endl;
	root->left=buildTree(root->left);
	cout<<"Enter data to right of "<<data<<endl;
	root->right=buildTree(root->right);
	return root;
}
void levelOrderTraversal(Node *root){
	queue<Node *> container;
	container.push(root);
	// while(!container.empty()){
	// 	Node *temp=container.front();
	// 	// container.push(temp);
	// 	cout<<temp->val<<endl;
	// 	if(temp->left)
	// 		container.push(temp->left);
	// 	if(temp->right)
	// 		container.push(temp->right);
	// 	container.pop();
	// }
}
int main()
{
	Node *root=NULL;
	root=buildTree(root);
	// levelOrderTraversal(root);
	return 0;
}