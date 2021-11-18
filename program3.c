#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack[MAX],item;
int ch,top=-1,status=0;
void push(int stack[],int item)
{
    if(top==(MAX-1))
    printf("\n\n Stack Overflow");
    else
    {
        stack[++top]=item;
        status++;
    }

}
int pop (int stack[])
{
    int ret;
    if(top==-1)
        printf("\n\n Stack underflow");
    else
    {
            ret=stack[top--];
            status--;
            printf("\n popped element is %d",ret);
    }    
        return ret;

}
void palindrome(int stack[])
{
    int i,temp,count=0;
    temp=status;
    for(i=0;i<temp;i++)
    {
        if(stack[i]==pop(stack))
        count++;
    }
    if (temp==count)
    printf("\n Stack contents are Palindrome");
    else
    printf("\n Stack contents are not Palindrome");
}
void display(int stack[])
{
    int i;
    printf("\n Stack contents are:");
    if (top==-1)
    printf("\n Stack is empty");
    else
    {
        for(i=top;i>=0;i--)
        printf("\n......\n|%d|",stack[i]);
        printf("\n");
    }
}
  
void main()
{       do
        {
            printf("\n\n......Main Menu......\n");
            
            printf("\n 1.Push(Insert) in stack\n");
            printf("\n 2.Pop(Delete) from the stack\n");
            printf("\n 3.Palindrome check using stack\n");
            printf("\n 4.Exit (End the Execution\n");
            printf("\n Enter your choice\n");
            scanf("%d",&ch);
            switch(ch)

                {
                 case 1:printf("\n Enter an element to be pushed:");
                 scanf("%d",&item);
                 push(stack,item);
                 display(stack);
                 break;
                 case 2:pop(stack);
                 display(stack);
                 break;
                 case 3:palindrome(stack);
                 break;
                 case 4: exit(0);
                 default:printf("\n Enter a valid choice ");
                }
        }while(ch!=4);
}