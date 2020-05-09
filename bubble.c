#include<stdio.h>
main()
{
  int i,j,temp=0,a[20],n,x;
  printf("\n Enter the array size : ");
  scanf("%d",&n);
  x= n; 
  for(i=0;i<n;i++)
  {
      printf("\n Enter the array element %d :",i+1);
      scanf("%d",&a[i]);
  }

  for(i=1;i<n;i++)
  {
     for(j=0;j<i;j++)
     {
       if(a[j]>a[i])
       {
           temp= a[j];
           a[j]= a[i];
           a[i]= temp;
       }
    
} 
  }
  for(i=0;i<x;i++)
    printf("%d,",a[i]);
}
