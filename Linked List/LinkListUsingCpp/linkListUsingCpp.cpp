#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
	Node(int val){
		data=val;
		next=NULL;
	}
};
void insertAtHead(Node* &head, int val){
	Node* n=new Node(val);
	n->next=head;
	head=n;
}
void insertAtTail(Node* &head, int val){
	Node* n=new Node(val);
	if(head==NULL){
		head=n;
		return;
	}
	Node* temp=head;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=n;
}
void print(Node* head){
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
}
void reverse(Node* &head){
	Node* prev=NULL;
	Node* current=head;
	Node* nextptr;
	while(current){
		nextptr=current->next;
		current->next=prev;
		prev=current;
		current=nextptr;
	}
	head=prev;
}
Node* reverseRecursive(Node* &head){
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	Node* n=reverseRecursive(head->next);
	head->next->next=head;
	cout<<head->data<<endl;
	head->next=NULL;
	return n;
}
int main()
{
	Node* head=NULL;
	insertAtTail(head,4);
	insertAtTail(head,5);
	insertAtHead(head,2);
	insertAtTail(head,3);
	// print(head);
	// cout<<endl;
	// reverse(head);
	// print(head);
	head=reverseRecursive(head);
	// cout<<endl;
	print(head);
	return 0;
}