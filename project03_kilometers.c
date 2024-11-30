#include <stdio.h>
float metersToKilometers(float meters);
float kilometersToMeters(float kilometers);
float gramsToKilograms(float grams);
float kilogramsToGrams(float kilograms);

int main() {
    int category, choice;
    float value, convertedValue;
    printf("Unit Conversion Program\n");
    printf("Choose a category:\n");
    printf("1. Length (meters/kilometers)\n");
    printf("2. Weight (grams/kilograms)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &category);

    if (category == 1) 
    {
        printf("\nLength Conversion Options:\n");
        printf("1. Meters to Kilometers\n");
        printf("2. Kilometers to Meters\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value in meters: ");
            scanf("%f", &value);
            convertedValue = metersToKilometers(value);
            printf("Value in kilometers: %.3f km\n", convertedValue);
        } else if (choice == 2) {
            printf("Enter value in kilometers: ");
            scanf("%f", &value);
            convertedValue = kilometersToMeters(value);
            printf("Value in meters: %.3f m\n", convertedValue);
        } else {
            printf("Invalid choice! Please run the program again.\n");
        }
    } else if (category == 2) {
        // Weight conversions
        printf("\nWeight Conversion Options:\n");
        printf("1. Grams to Kilograms\n");
        printf("2. Kilograms to Grams\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value in grams: ");
            scanf("%f", &value);
            convertedValue = gramsToKilograms(value);
            printf("Value in kilograms: %.3f kg\n", convertedValue);
        } else if (choice == 2) {
            printf("Enter value in kilograms: ");
            scanf("%f", &value);
            convertedValue = kilogramsToGrams(value);
            printf("Value in grams: %.3f g\n", convertedValue);
        } else {
            printf("Invalid choice! Please run the program again.\n");
        }
    } else {
        printf("Invalid category! Please run the program again.\n");
    }

    return 0;
}

float metersToKilometers(float meters) {
    return meters / 1000.0;
}

float kilometersToMeters(float kilometers) {
    return kilometers * 1000.0;
}

float gramsToKilograms(float grams) {
    return grams / 1000.0;
}

float kilogramsToGrams(float kilograms) {
    return kilograms * 1000.0;
}
