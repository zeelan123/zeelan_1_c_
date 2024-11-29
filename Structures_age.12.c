#include<stdio.h>
struct student 
{
char student_name[50];
int age;
char gender;
char college_name[50];
char department_name[50];
};
int main()
{
  struct student s1;
  printf(" enter name");
  scanf("%s",s1.student_name);
  printf("enter age");
  scanf("%d",&s1.age);
  printf("enter gendre");
  scanf("%c",&s1.gender);
  printf("enter college_name:");
  scanf("%s",s1.college_name);
  printf("enter department_name:");
  scanf("%s",s1.department_name);
  printf("student_name%s\n,student_ age%d\n,student_gender%s\n,college_name%s\n,s department_ name%s\n",s1.name,s1.age,s1.gendre,s1.college_name,s1.department_name); 
  
  return 0;
  
  
}
