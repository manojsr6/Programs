#include<stdio.h>
main()
{
   int a[3][3]= {{1,2,3},{4,5,6},{7,8,9}},i,j,k,product=0,sum=0;
   for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    { printf("\n Enter the array element (%d,%d) : ",i,j);
      /*scanf("%d",&a[i][j]);*/
    }
   for(i=0;i<3;i++)
   {
    printf("These 4 elements are for %d, %d\n",0,i);
    for(j=1;j<3;j++)
    {
      for(k= 0; k < 3; k++)
      {
        if(i == k)
	  continue;
	printf("%d  ",a[j][k]);
      }
    }
  }
}
