#include <stdio.h>
#include <stdlib.h>

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
struct ListNode *prevnode, *newnode, *currentnode, *prevnode1, *newnode1, *currentnode1, *l3,*temp;
    int count=-1,total=0,total1=0;
    prevnode=prevnode1=0;
    newnode=currentnode=l1;
    newnode1=currentnode1=l2;
    while(newnode!=0)
  {
    newnode=newnode->next;
    currentnode->next=prevnode;
    prevnode=currentnode;
    currentnode=newnode;

    newnode1=newnode1->next;
    currentnode1->next=prevnode1;
    prevnode1=currentnode1;
    currentnode1=newnode1;
        count++;
  }
   l3=0;
  if (count==0 && l1->val==l2->val==0){
      newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=0;
        newnode->next=0;
      if (l3==0){
    temp=l3=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
      printf("%d\n",l3->val);
      return l3;
  }
    l1=prevnode;
    l2=prevnode1;
    while(l1!=0)
    {
        total+=l1->val*pow(10,count);
        total1+=l2->val*pow(10,count);
        l1=l1->next;
        l2=l2->next;
        count--;
    }
    int total3=(total+total1),rem=total3;
    l3=0;
    while(total3!=0)
    {
        rem= total3%10;
        newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=rem;
        newnode->next=0;
        if (l3==0){
    temp=l3=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
        total3/=10;
    }
    printf("%d %d",total,total1);
    return l3;
}

int main()
{
    struct ListNode *l1,*l2,*temp,*newnode;
    l1,l2=0;
    int choice=3,i=0;
    while (i<choice)
   {
    newnode=(struct node*)malloc(sizeof(struct ListNode));
    /**memory is allocated for node dynamically**/
    i++;
    printf("enter data %d ",i);
    scanf("%d",&newnode->val);
    /**if only 1 element in linked list then newnode->next=0, so it is initialized AS 0**/
    newnode->next=0;
    /**for first node only this is valid*/
    if (l1==0){
    temp=l1=newnode;
    }
    /**temp contains the address of previous node**/
    else{
        temp->next=newnode;/**the previous node->next value get assigned by this**/
        temp=newnode;
    }

}


int choice=3,i=0;
    while (i<choice)
   {
    newnode=(struct node*)malloc(sizeof(struct node));
    /**memory is allocated for node dynamically**/
    i++;
    printf("enter data %d ",i);
    scanf("%d",&newnode->data);
    /**if only 1 element in linked list then newnode->next=0, so it is initialized AS 0**/
    newnode->next=0;
    /**for first node only this is valid*/
    if (l2==0){
    temp=l2=newnode;
    }
    /**temp contains the address of previous node**/
    else{
        temp->next=newnode;/**the previous node->next value get assigned by this**/
        temp=newnode;
    }

}

printf("\n%d",addTwoNumbers(l1,l2));
    return 0;
}
