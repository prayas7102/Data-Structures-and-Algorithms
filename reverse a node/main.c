#include <stdio.h>
#include <stdlib.h>
/**basic linked list prg**/
/** struct data type is created to initialize a node*/
struct node{
int data;
struct node* next;
};

/*reverse the linked list*/

struct node *reverse(struct node *prevnode,struct node *currentnode,struct node *head, struct node *newnode, struct node *temp)
{
    printf("\n\nReversed node list\n");
    prevnode=0;
    newnode=currentnode=head;
    while(newnode!=0)
  {
    newnode=newnode->next;
    currentnode->next=prevnode;
    prevnode=currentnode;
    currentnode=newnode;

  }
    head=prevnode;
    return head;
}

void printlist(struct node *head, struct node *temp)
{
    int s[10];
    int i=0;
/**print reverse node***/
temp=head;/**address of first node gets assigned to this**/
printf("\n");
while(temp!=0)
  {
    s[i]=temp->data;
    printf("%d\t",temp->data);
    temp=temp->next;/**the address of next node gets assigned by this to temp for iterating**/
    i++;
  }
  for(int i=0;i<10;i++){
    printf("%d\n",s[i]);
  }
}

int main()
{
    struct node *temp,*newnode,*head,*prevnode,*currentnode;
    /**head pointer is created to store the address of 1st node**/
    int choice=1,i=0;
    head=0;/**initiallly heda=0 or NULL*/

/**node construction over*/

    while (choice)
   {
    newnode=(struct node*)malloc(sizeof(struct node));
    /**memory is allocated for node dynamically**/
    i++;
    printf("enter data %d ",i);
    scanf("%d",&newnode->data);
    /**if only 1 element in linked list then newnode->next=0, so it is initialized AS 0**/
    newnode->next=0;
    /**for first node only this is valid*/
    if (head==0)
    {
      temp=head=newnode;
    }
    /**temp contains the address of previous node**/
    else
    {
        temp->next=newnode;/**the previous node->next value get assigned by this**/
        temp=newnode;
    }
    printf("do yo want to continue? (0,1) ");
    scanf("%d",&choice);
  }

/**node construction over**/

/**print the given node**/
printlist(head, temp);

/**reverse operation*/
head= reverse(prevnode,currentnode,head,newnode,temp);

/*print reverse node*/
printlist(head, temp);
return 0;
}
