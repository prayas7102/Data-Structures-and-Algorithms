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
Node *temp;
void reverseRecursive(Node* &head){
	if (head==NULL||head->next==NULL)
	{
		temp=head;
		return ;
	}
	reverseRecursive(head->next);
	head->next->next=head;
	head->next=NULL;
}
Node* reversekNodes(Node* &head, int k){
	Node* prev=NULL;
	Node* current=head;
	Node* nextptr;
	int i=0;
	while(current && i<k){
		nextptr=current->next;
		current->next=prev;
		prev=current;
		current=nextptr;
		i++;
	}
	if(nextptr!=NULL){
		head->next=reversekNodes(nextptr,k);
	}
	return prev;
}
int main()
{
	Node* head=NULL;

// insert value in link list
	cout<<"link list:"<<endl;
	insertAtTail(head,4);
	insertAtTail(head,5);
	insertAtHead(head,2);
	insertAtHead(head,10);
	insertAtTail(head,3);
	insertAtTail(head,9);
	print(head);

	cout<<endl;
// reverse linked list
	cout<<"link list reversed:"<<endl;
	reverse(head);
	print(head);

	cout<<endl;
// reverse linked list using recursion
	cout<<"link list reversed: using recursion"<<endl;
	reverseRecursive(head);
	head=temp;
	print(head);

	cout<<endl;
// reverse k nodes in link list
	cout<<"link list k nodes reversed:"<<endl;
	int k=4;
	head=reversekNodes(head,k);
	print(head);

	return 0;
}