#include<stdio.h>
main()
{
  int i,n,a[20],max;
  printf("\n Enter the array size :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
     printf("\n Enter the array element %d :",i+1);
     scanf("%d",&a[i]);
  }
  max= a[0];
  for(i=0;i<n;i++)
  {
     if(max<a[i])
      max= a[i];
  }
  printf("\n Maximum element of an array %d",max);
}
 
 
