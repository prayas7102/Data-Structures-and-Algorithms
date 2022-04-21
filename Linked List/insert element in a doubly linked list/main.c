#include <stdio.h>
#include <stdlib.h>
/**basic linked list prg**/
/** struct data type is created to initialize a node*/
struct node{
int data;
struct node* next, *prev; /**prev node for doubly linked list*/
}*head,*temp;

/**for inserting a node at the begining**/
int insertbeg(int pos, struct node *temp, struct node *head, struct node *newnode)
{
   newnode->next=head;
   head=newnode;

   return head;
}
/*for inserting node at the middle and end**/
int insertmiddle(int pos, struct node *temp, struct node *head, struct node *newnode)
{
int i=1;
   temp=head;
   while((i)<pos-1)
   {
      temp=temp->next;
      i++;
   }
             newnode->prev=temp;

      newnode->next=temp->next;
   temp->next=newnode;
            newnode->next->prev=newnode;

   return temp;
}

void printlist(struct node *temp, struct node *head)
{
temp=head;/**address of first node gets assigned to this**/
while(temp!=0)
    {
    printf("\n%d",temp->data);
    temp=temp->next;/**the address of next node gets assigned by this to temp for iterating**/
    }
}

int main()
{
    struct node *newnode;
    /**head pointer is created to store the address of 1st node**/
    int choice=1,i=0;
    head=0;/**initiallly heda=0 or NULL*/
    while (choice)
   {
    newnode=(struct node*)malloc(sizeof(struct node));
    /**memory is allocated for node dynamically**/
    i++;
    printf("enter data %d ",i);
    scanf("%d",&newnode->data);
    /**if only 1 element in linked list then newnode->next=0, so it is initialized AS 0**/
    newnode->next=0;
    newnode->prev=0;
    /**for first node only this is valid*/
    if (head==0){
    temp=head=newnode;
    }
    /**temp contains the address of previous node**/
    else{
        temp->next=newnode;/**the previous node->next value get assigned by this**/
        newnode->prev=temp;
        temp=newnode;
    }
    printf("do yo want to continue? (0,1) ");
    scanf("%d",&choice);
}

printlist(temp, head);
int pos=2;
printf("\n enter new node\n");
newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    newnode->prev=0;
scanf("%d",&newnode->data);
temp= insertmiddle(pos,temp,head,newnode);
printlist(temp, head);
return 0;
}
