#include <stdio.h>

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is positive
    if (number > 0) {
        printf("The number is positive.\n");
    }

    printf("Program ends here.\n");

    return 0;
}

