/* Matrix add - algo*/

#include<stdio.h>
main()
{
  int a[20][20],b[20][20],c[20][20],i,j,n,m;
  int x;
  printf("\n Enter the size of rows "); 
  scanf("%d",&n);
  printf("\n Enter the size of columns ");
  scanf("%d",&m);
  printf(" \n 1. 2dimensional array addition ");
  printf("\n  2. 2dimensional array sub ");
  printf("\n  3. Exit ");
  printf(" \n Enter your choice ");
  scanf(" %d",&x);
  switch(x)
  {
    case 1:
            if(m==n)
            {
               printf("\n Enter first array elements ");
               for(i=0;i<n;i++)
                for(j=0;j<m;j++)
               {
                 printf(" \n Enter the element (%d,%d): ",i,j);
                 scanf("%d",&a[i][j]);
               } 
               printf("\n Enter second array elements ");
               for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                 {
                   printf(" \n Enter the element (%d,%d): ",i,j);
                   scanf("%d",&b[i][j]);
                 } 
               for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                 c[i][j]=  a[i][j]+b[i][j];
               for(i=0;i<n;i++)
               {
                for(j=0;j<m;j++)
                 printf("%d,",c[i][j]);
                printf("\n");
              }
          }
          break;
  case 2:
          if(m==n)
          {
               printf("\n Enter first array elements ");
               for(i=0;i<n;i++)
                for(j=0;j<m;j++)
               {
                 printf(" \n Enter the element (%d,%d): ",i,j);
                 scanf("%d",&a[i][j]);
               } 
               printf("\n Enter second array elements ");
               for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                 {
                   printf(" \n Enter the element (%d,%d): ",i,j);
                   scanf("%d",&b[i][j]);
                 }
              for(i=0;i<n;i++)
               for(j=0;j<m;j++)
                 c[i][j]=  b[i][j]-a[i][j];
              for(i=0;i<n;i++)
              {
               for(j=0;j<m;j++)
                printf(" %d,",c[i][j]);
               printf("\n");
              }
          } 
          break;
 case 3:
        printf("\n Exiting from the program ");
        break;
 }
  
}
