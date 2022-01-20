#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct student
{
 char usn[10];
 char name[30];
 char branch[5];
 int sem;
 char phno[15];
 struct student *link; //Self referential pointer.
};
typedef struct student NODE;
NODE* getnode(NODE* first)
{
 NODE* x;
 x=(NODE*)malloc(sizeof(NODE)); //Create first NODE
 printf("\nEnter USN, Name, Branch, Sem, Ph.No\n");
 gets(x->usn);
 gets(x->name);
 gets(x->branch);
 scanf("%d",&(x->sem));
 gets(x->phno);
 x->link=NULL;
 first=x;
 return first;
}
NODE* display(NODE* first)
{
 NODE* cur;
 int count=0;
 if(first == NULL)
 printf("\nNo student data\n");
 else
    {
     cur=first;
     printf("\n----STUDENT DATA----\n");
     printf("\nUSN\tNAME\t\tBRANCH\tSEM\tPh.NO.");
     while(cur!=NULL)
        {
         printf("\n%s\t%s\t\t%s\t%d\t%s\t", cur->usn, cur->name, cur->branch, cur->sem, cur->phno);
         cur = (cur->link);
         count++;
        }
     printf("\nThe no. of nodes in list is: %d",count);
    }
 return first;
}
NODE *create(NODE* first)
{
 NODE* temp;
 if(first==NULL)
    {
     temp=getnode(first);
     first=temp;
    }
 else
    {
     temp=getnode(first);
     first=temp;
    }
 return first;
}
NODE* insert_front(NODE* first)
{
 first=create(first); //create()insert nodes at front.
 return first;
}
NODE* insert_rear(NODE* first)
{
 NODE* cur,* temp;
 cur=first;
 if(first == NULL)
    {
     temp=getnode(first);
     first=temp; //set first node to be head
    }
 else
    {
     temp=getnode(first);
     while(cur->link!=NULL)
        {
         cur=cur->link;
        }
     cur->link=temp;
    }
 return first;
}
NODE* del_front(NODE* first)
{
 NODE* cur;
 if(first==NULL)
 printf("\nList is Empty\n");
 else
{
cur=first;
first=first->link;
free(cur);
printf("\nFront(first)node is deleted");
}
 return first;
}
NODE* del_rear(NODE* first)
{
 NODE *cur,*prev;
 if(first==NULL)
    {
     printf("List is empty\n");
     return first;
    }
 if(first->link==NULL)
    {
     printf("\nLast(end)entry is deleted");
     free(first);
     return NULL;
    }
 prev=NULL;
 cur=first;
 while(cur->link!=NULL)
    {
     prev=cur;
     cur=cur->link; 
    }
 prev->link=NULL;
 free(cur);//Delete last NODE...
 printf("\nLast(end) entry is deleted");
 return first;
}
NODE* stack(NODE* first)
{
 int ch;
 do
    {
     printf("\nSSL used as Stack...");
     printf("\n 1.Insert at Front(PUSH) \t 2.Delete from Front(POP))\t3.Exit");
     printf("\nEnter your choice: ");
     scanf("%d", &ch);
     switch(ch)
        {
         case 1: first=insert_front(first); break;
         case 2: first=del_front(first); break;
         case 3: break;
        }
     first=display(first);
    }
 while(ch!=3);
 return first;
}
void main()
{
 int ch, i, n;
 NODE* first;
 first=NULL;
 printf("\n*----------Student Database-----------*");
 while(1)
    {
     printf("\n 1.Create\t 2.Display\t 3.Insert_front\t 4.Insert_rear\t 5.Delete_front\t 6.Delete_rear\t 7.Stack\t 8.Exit");
     printf("\nEnter your choice: ");
     scanf("%d", &ch);
     switch(ch)
        {
         case 1: printf("\nHow many student data you want to create: ");
         scanf("%d", &n);
         for(i=0;i<n;i++)
         first=create(first);//Call to Create NODE...
         break;
         case 2: first=display(first); //Call to Display...
         break;
         case 3: first=insert_front(first); //Call to Insert...
         break;
         case 4: first=insert_rear(first);
         break;
         case 5: first=del_front(first); //Call to delete
         break;
         case 6: first=del_rear(first);
         break;
         case 7: first=stack(first);
         break;
         case 8: exit(0); //Exit...
         default:printf("Enter valid choice\n");
        }
    }
}