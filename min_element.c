#include<stdio.h>
main()
{
  int i,a[20],n, min;
  printf("\n Enter the array size ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\n Enter the array element %d :", i+1);
    scanf("%d",&a[i]);
  }
  min= a[0];
  for(i=0;i<n;i++)
  {
    if(min>a[i])
     min=a[i];
  }
  printf("minimum of numbers entered %d ",min);
}

