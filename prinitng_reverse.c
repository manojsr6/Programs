#include<stdio.h>
main()
{
  int a[20],i,n;
  printf(" \n Enter the array size :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\n Enter the array element %d : ",i+1);
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
   printf("%d,",a[i]);
  printf("\n Array in reverse order ");
  for(i=n-1;i>=0;i--)
   printf("%d,",a[i]);
} 
 
