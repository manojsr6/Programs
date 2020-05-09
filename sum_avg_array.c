#include<stdio.h>
main()
{
  int sum=0,avg=0,i,n,a[20];
  printf("\n Enter the array size:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
     printf("\n Enter array element %d : ",i+1);
     scanf("%d",&a[i]);
     sum= sum+a[i];
  }
  avg= sum/n;
  printf("\n Sum  and average of array is %d,%d\n",sum,avg);
}

