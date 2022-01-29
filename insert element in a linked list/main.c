#include <stdio.h>
#include <stdlib.h>
struct  node{
int data;
struct node* next;
};
/**for printing the linked list**/
void printlist(struct node* temp, struct node *head)
{
    printf("\nprint all the elements\n");
    temp=head;
   while (temp!=0)
   {
       printf("%d\n",temp->data);
       temp=temp->next;
   }
}
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
int    i=1;
   temp=head;
   while((i+1)<pos)
   {
      temp=temp->next;
      i++;
   }
   newnode->next=temp->next;
   temp->next=newnode;
   temp=head;
   return temp;
}

int main()
{
   struct node *newnode,*head,*temp;
   int choice=1,i=0;
   head=0;
   while(choice)
   {
       newnode=(struct node*)malloc(sizeof(struct node));
       newnode->next=0;
       printf("enter the value of data %d ",i+1);
       i++;
       scanf("%d",&newnode->data);
       if (head==0)
       {
           temp=head=newnode;
       }
       else{
        temp->next=newnode;
        temp=newnode;
       }
       printf("do yo want to continue (0,1)\n");
       scanf("%d",&choice);
   }
   int pos;
   printf("\n List insertion\n");
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("enter the element you want to insert ");
   scanf("%d",&newnode->data);
   printf("enter position ");
   scanf("%d",&pos);
   if (pos!=1){
   temp=insertmiddle(pos,temp,head,newnode);
   }
   else{
    head=insertbeg(pos,temp,head,newnode);/*adress stored at head is changed when a node is introduced at 1st position**/
   }
   printlist(temp,head);

   return 0;
}
