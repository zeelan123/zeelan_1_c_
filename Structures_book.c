#include<stdio.h>
struct book
{
  char bookname;
  char authorname;
  float price;
};
int main()
{
  struct book b1;
  printf("enter the bookname\n");
  scanf("%c",b1.bookname);
  printf("enter the authorname\n");
  scanf("%c",b1.authorname);
  printf("enter the price\n");
  scanf("%f",b1.price);
  printf("\nbookdetails\n");
  printf("bookname%c\nauthorname%c\nprice\n",b1.bookname,b1.authorname,b1.price);
return 0;
  
}
