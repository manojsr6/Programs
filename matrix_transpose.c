#include<stdio.h>
main()
{
  int a[20][20],b[20][20],c[20][20],i,j,n,m;
  printf("\n Enter the row size of array: ");
  scanf("%d",&n);
  printf("\n Enter the column size :");
  scanf("%d",&m);
  if(m==n)
  {
    printf("\n Enter the array elements of a and b ");
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
      {
        printf("\n Enter the array element of a(%d,%d): ",i,j);
        scanf("%d",&a[i][j]); 
      }
    for(i=0;i<n;i++)
     for(j=0;j<m;j++)




        c[j][i]= a[i][j];
    
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
         printf("%d",c[i][j]);
      printf("\n");
   }
  }
}
       
    
       
      
