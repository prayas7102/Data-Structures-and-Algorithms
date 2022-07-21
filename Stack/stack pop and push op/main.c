#include <stdio.h>
int stack[5];
int top=-1;

void push()
{
    int x;
    printf("enter data  ");
    scanf("%d",&x);
    if (top==4)
    {
        printf("\nOverflow condition");
    }
    else{
        top++;
        stack[top]=x;
     }
}
void pop()
{
    printf("%d",top);
    if (top==-1)
    {
        printf("\nunderflow\n");
    }
    else
    {
        top--;
        display();
    }
}
void display()
{
    printf("\nelements are\n");
    if (top==-1){
        printf("\nUnderflow condition\n");
    }
    for(int k=0;k<top+1;k++)
    {
        printf("%d\n",stack[k]);
    }
}
int main()
{
    int j=0,choice=1;
    while(j<5)
    {
    push();
    j++;
    }
    j=0;
    display();
    while(choice!=0 && j<5)
    {
    printf("\n do you want to delete?(0,1)");
    scanf("%d",&choice);
    if(choice==0){
        break;
    }
    pop();
    j++;
    }
    return 0;
}
