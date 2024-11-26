#include <stdio.h>
int main()
{
  int n,i=1,sum=0;
  printf("enter the value of n:");
  scanf("%d",&n);
  while(i<=n)
    {
      sum+=i;
      i++;
      
    }
printf("sum of first%d natural numbers is %d"\n ",n,sum);

return 0;
}
