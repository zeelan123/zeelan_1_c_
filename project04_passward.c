
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int isValidPassword(char password[]);

int main() {
    char password[100];

    // Prompt the user for a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check if the password is valid
    if (isValidPassword(password)) {
        printf("Password is valid!\n");
    } else {
        printf("Password is invalid. Please ensure it meets the following criteria:\n");
        printf("- At least 8 characters long\n");
        printf("- Contains at least one uppercase letter\n");
        printf("- Contains at least one lowercase letter\n");
        printf("- Contains at least one digit\n");
        printf("- Contains at least one special character (e.g., @, #, $, etc.)\n");
    }

    return 0;
}

// Function to check if the password is valid
int isValidPassword(char password[]) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    if (length < 8) {
        return 0; // Password too short
    }

    // Check each character in the password
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (ispunct(password[i])) { // Checks for special characters
            hasSpecial = 1;
        }
    }

    // Password is valid if all conditions are met
    return hasUpper && hasLower && hasDigit && hasSpecial;
}
