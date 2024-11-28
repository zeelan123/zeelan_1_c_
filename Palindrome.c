#include<stdio.h>
int main()
{
 int num,reversed=0,reminder,original;
   printf("enter a integer:") ;
   scanf("%d",&num);
   original=num;
   while (num !=0)
   {
       reminder=num %10;
   reversed=reversed *10 + reminder ;
   num = num / 10;
   }
   if(original==reversed )
   {
   printf("%d is a polindrome.\n", original);
   }
   else
   {
   printf("%d is not a palindrome.\n", original);
   }
   return 0;
}
