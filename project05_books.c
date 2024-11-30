
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50

// Book structure
typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
} Book;

// Function prototypes
void addBook(Book books[], int *count);
void displayBooks(const Book books[], int count);
void searchBook(const Book books[], int count);
void deleteBook(Book books[], int *count);

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        // Menu
        printf("\nBook Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
                break;
            case 4:
                deleteBook(books, &count);
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

// Function to add a book
void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Error: Cannot add more books. Database is full.\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &books[*count].id);
    printf("Enter Book Title: ");
    getchar(); // To clear the newline character
    fgets(books[*count].title, TITLE_LEN, stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = '\0'; // Remove newline
    printf("Enter Author Name: ");
    fgets(books[*count].author, AUTHOR_LEN, stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = '\0'; // Remove newline

    (*count)++;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks(const Book books[], int count) {
    if (count == 0) {
        printf("No books in the database.\n");
        return;
    }

    printf("\nBook List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
    }
}

// Function to search for a book by ID
void searchBook(const Book books[], int count) {
    if (count == 0) {
        printf("No books in the database.\n");
        return;
    }

    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("Book Found: ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
            return;
        }
    }

    printf("Book with ID %d not found.\n", id);
}

// Function to delete a book by ID
void deleteBook(Book books[], int *count) {
    if (*count == 0) {
        printf("No books in the database.\n");
        return;
    }

    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (books[i].id == id) {
            // Shift all books after the deleted one
            for (int j = i; j < *count - 1; j++) {
                books[j] = books[j + 1];
            }
            (*count)--;
            printf("Book with ID %d deleted successfully.\n", id);
            return;
        }
    }

    printf("Book with ID %d not found.\n", id);
}
