/*Insertion sort algo*/

#include<stdio.h>
main()
{
   int i,j,temp=0,a[20],b[20],n;
    printf("\n Enter the array size ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
     {
        printf("\n Enter the array element %d",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0,j=1;i<n,j<n;i++,j++)
    {
       if(a[j]<a[i])
       {
         temp= a[j];
         a[j]= a[i];
         a[i]= temp;
       }
       else
       {
          temp= a[i];
          a[i]= a[j];
          a[j]= temp;
       }
    }
    for(i=0;i<n;i++)
      printf("%d,",a[i]);
}

           

