
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[50], str3[150];
    
    // Input first string
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline
    
    // Input second string
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline

    // Copy str1 to str3
    strcpy(str3, str1);
    printf("\nString after copying: %s\n", str3);

    // Concatenate str2 to str3
    strcat(str3, str2);
    printf("String after concatenation: %s\n", str3);

    // Compare str1 and str2
    int comparison = strcmp(str1, str2);
    if (comparison == 0) {
        printf("\nThe two strings are equal.\n");
    } else if (comparison < 0) {
        printf("\nThe first string is less than the second string.\n");
    } else {
        printf("\nThe first string is greater than the second string.\n");
    }

    // Display lengths of strings
    printf("\nLength of the first string: %lu\n", strlen(str1));
    printf("Length of the second string: %lu\n", strlen(str2));
    printf("Length of the concatenated string: %lu\n", strlen(str3));

    return 0;
}
