include <stdio.h>
struct Employee
{
    char name[50];
    int id;
    float salary;
};
float calculateAverageSalary(struct Employee employees[], int numEmployees) 
{
    float totalSalary = 0.0;
    for (int i = 0; i < numEmployees; i++) {
        totalSalary += employees[i].salary;
    }
    return totalSalary / numEmployees;
}

int main()
{
    int numEmployees;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    struct Employee employees[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    float averageSalary = calculateAverageSalary(employees, numEmployees);
    printf("\nThe average salary of the employees is: %.2f\n", averageSalary);

    return 0;
}
