#include <stdio.h> 

struct address 
{
char city[40];
int pin;
};

struct person 
{
char name[50];
struct address ab;
};

int main()
{
  struct person p;
  printf("enter name");
  scanf("%s",p.name);
  printf("enter city");
  scanf("%s",p.ab.city);
  printf("enter pin");
  scanf("%d",&p.ab.pin);
printf("\nperson details ");
printf("name%s\n,city%s\n,pin%d\n",p.name,p.ab.city,p.ab.pin);
return 0;
}

