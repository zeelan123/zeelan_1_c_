#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

// Structure to store student information
typedef struct {
    int rollNumber;
    char name[NAME_LEN];
    float marks;
} Student;

// Function prototypes
void addStudent(Student students[], int *count);
void viewStudents(const Student students[], int count);
void editStudent(Student students[], int count);
void deleteStudent(Student students[], int *count);

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        // Menu
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Edit Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                editStudent(students, count);
                break;
            case 4:
                deleteStudent(students, &count);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new student
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Cannot add more students. Database is full.\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Enter Name: ");
    getchar(); // To consume the leftover newline character
    fgets(students[*count].name, NAME_LEN, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0'; // Remove newline
    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents(const Student students[], int count) {
    if (count == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("Roll Number | Name                 | Marks\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%11d | %-20s | %.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
}

// Function to edit a student's record
void editStudent(Student students[], int count) {
    if (count == 0) {
        printf("No students in the database.\n");
        return;
    }

    int rollNumber;
    printf("Enter Roll Number of the student to edit: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Editing details for Roll Number %d:\n", rollNumber);
            printf("Enter New Name: ");
            getchar(); // To consume the leftover newline character
            fgets(students[i].name, NAME_LEN, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline
            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);
            printf("Record updated successfully!\n");
            return;
        }
    }

    printf("Student with Roll Number %d not found.\n", rollNumber);
}

// Function to delete a student's record
void deleteStudent(Student students[], int *count) {
    if (*count == 0) {
        printf("No students in the database.\n");
        return;
    }

    int rollNumber;
    printf("Enter Roll Number of the student to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Shift records to fill the gap
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
            return;
        }
    }

    printf("Student with Roll Number %d not found.\n", rollNumber);
}

