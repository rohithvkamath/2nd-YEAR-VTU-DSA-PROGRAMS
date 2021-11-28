#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int *a , n, elem, i, pos;
void create()
{
   printf("\nEnter the size of the elements: ");
   scanf("%d", &n);
   a=(int*)malloc(n*sizeof(int));
   printf("\nEnter the elements :\n");
   for(i=0; i<n; i++)
   scanf("%d", a+i);
}
void display()
{
   int i;
   printf("\nThe elements are:\n");
   for(i=0; i<n; i++)
   {
    printf("%d\t", *(a+i));
   }
}
void insert()
{

   printf("\nEnter the position for the new element: ");
   scanf("%d", &pos);
   printf("\nEnter the element to be inserted: ");
   scanf("%d", &elem);
   for(i=n-1; i>=pos; i--)
   {
      *(a+i+1) = *(a+i);
   }
   *(a+pos-1)= elem;
   n = n+1;
   printf("\nThe elements after insertion is : \n");
   for(i=0; i<n; i++)
   {
    printf("%d\t", *(a+i));
   }
}
void del() //deleting an array element
{
   printf("\nEnter the position of the element to be deleted: ");
   scanf("%d", &pos);
   pos-=1;
   elem = *(a+pos);
   for(i=pos; i<n-1; i++)
   {
     *(a+i) = *(a+i+1);
   }
   n = n-1;
   printf("\nThe deleted element is = %d\n", elem);
   printf("\nThe elements after deletion is: \n");
   for(i=0; i<n; i++)
   {
    printf("%d\t", *(a+i));
   }
}
void main()
{
   int ch;

   do
   {
      printf("\n\n--------Menu-----------\n");
      printf("1.Create\n 2.Display\n 3.Insert\n 4.Delete\n 5.Exit\n");
      printf("-------------------------------");
      printf("\nEnter your choice: ");
      scanf("%d", &ch);
      switch(ch)
      {
         case 1: create();
         break;
         case 2: display();
         break;
         case 3: insert();
         break;
         case 4: del();
         break;
         case 5: exit(0);
         break;
         default: printf("\nInvalid choice:\n");
         break;
      }
   }while(ch!=5);

}