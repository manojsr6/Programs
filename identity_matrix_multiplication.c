#include<stdio.h>
main()
{
  int i,j,a[20][20],b[20][20],c[20][20],k,n,m,p,q;
  printf("\n Enter the row and column size of array a : ");
  scanf("%d%d",&m,&n);
  printf("\n Enter the row and column size of array b : ");
  scanf("%d%d",&p,&q);
  if(p==n)
  {
    for(i=0;i<m;i++)
     {
      for(j=0;j<n;j++)
        {
          printf(" \n Enter the array element a(%d,%d) : ",i,j);
           scanf("%d",&a[i][j]);
        }
     }
    for(i=0;i<p;i++)
    {
     for(j=0;j<q;j++)
      {
        printf("\n Enter the array element b(%d,%d) : ",i,j);
        scanf("%d",&b[i][j]);
      }
}
     for(i=0;i<m;i++)
     {
       for(j=0;j<q;j++)
        {
          c[i][j]= 0;
          for(k=0;k<n;k++)
           c[i][j]= c[i][j]+ a[i][k]*b[k][j];
          printf("%d,",c[i][j]);
        }
      printf("\n");
    }
 }
 else
   printf("\n Given two matrixes cannot be multiplied");
}


