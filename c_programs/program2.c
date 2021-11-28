#include<stdio.h>
#include<stdlib.h>
char str[100],rep[100],pat[100],temp[100];
int i,j,x,y,m,n,found=0;
void is_match()
{
   i=j=x=y=m=n=0;
   while(str[i]!='\0')
   {
       if(str[m]==pat[n])
       {
           m+=1;n+=1;
           if(pat[n]=='\0')
           {
               for(x=0;rep[x]!='\0';x++,y++)
               {
                   found=1;
                   temp[y]=rep[x];
                   n=0;
                   i=m;
               }
           }
           else 
           {
               temp[y]=str[i];
               y+=1;i+=1;
               n=0;m=i;
           }
       }
    temp[y]='\0';
   }

}
void main()
{ 
    printf("Enter the Main string:\n");
    scanf("\n %s",str);
    printf("Enter the String Pattern to be replaces:\n");
    scanf("\n %s",pat);
    printf("Enter the String with which the pattern is to be replaced:\n");
    scanf("\n %s",rep);
    is_match();
    if(found==1)
    {
        printf("The String after replacing is: %s \n",temp);
    }
    else printf("Pattern element is not found...");
}