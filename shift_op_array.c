#include<stdio.h>
main()
{
  int i,j,n,temp=0,a[20],c,r,e=0;
  printf("\n 1.Left shift");
  printf("\n 2.Right shift ");
  printf("\n 3.Exit       ");
  printf("\n Enter your choice: ");
  scanf("%d",&c);
  switch(c)
  {
    case 1 : printf(" enter number of time shifting must do ?");
             scanf("%d",&r);
             printf("\n Enter the array size ");
             scanf("%d",&n);
             for(i=0;i<n;i++)
             {
                printf("\n Enter the array element %d: ",i+1);
                scanf("%d",&a[i]);
             }
             while(e<r)
             {
               temp= a[0];
               for(i=0;i<n;i++)
               {
                 a[i]= a[i+1];
                 if(i== n-1)
                   a[i]= temp;
                 printf("%d,",a[i]);
               }
               e++;
               printf("\n");
             }
             break;
  case 2:
             printf("\n Enter number of times l shifting must done ?" );
             scanf("%d",&r);
             printf("\n Enter the array size ");
             scanf("%d",&n);
             for(i=0;i<n;i++)
             {
               printf("\n Enter the array element %d:",i+1);
               scanf("%d",&a[i]);
              
             }
             while(e<r)
             {
               temp= a[n-1]; 
               for(i=n-1;i>=0;i--)
               {
                  a[i+1]=a[i]; 
                  if(i==0)
                    a[i]= temp;
               }
               for(i=0;i<n;i++)
               printf("%d,",a[i]);
               e++;
               printf("\n");
             }
             break;
 case 3:     printf("\n Exiting from the program ");
             break;
              
}
}

