#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int q[MAX],f=0,r=-1,count=0;
void insert (int item)
{
 if (count==MAX)
 printf("Queue Overflow\n");
 else
    {
     r=(r+1)%MAX;
     q[r]=item;
     count=count+1;
    }
}
int delet()
{
 int itemdel;
 if (count==0)
 return 0;
 else
{
itemdel=q[f];
f=(f+1)%MAX;
count=count-1;
return (itemdel);
}
}
void display()
{
 int i,j;
 if (count==0)
 printf("Q empty\n");
 else
    {
     i=f;
     for (j=1;j<=count;j++)
        {
         printf("%d\t",q[i]);
         i=(i+1)%MAX;
        }
    }
}
void main()
{
 int ch,item,itemdel;
 while (1)
    {
     printf("\nEnter the choice\n");
     printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
     scanf("%d",&ch);
     switch(ch)
        {
         case 1: printf("Enter the item\n");
         scanf("%d",&item);
         insert(item);
         break;
         case 2: itemdel=delet();
         if (itemdel)
         printf("The deleted item is %d\n",itemdel);
         else
         printf("Queue underflow\n");
         break;
         case 3: display();
         break;
         case 4: exit(0);
         default: printf("Enter a valid choice\n");
        }
    }
 getch();
}