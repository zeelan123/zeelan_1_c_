#include <stdio.h>
float fahrenheitToCelsius(float fahrenheit);
float celsiusToFahrenheit(float celsius);

int main() {
    int choice;
    float temperature, convertedTemperature;
    printf("Temperature Conversion Program\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        convertedTemperature = fahrenheitToCelsius(temperature);
        printf("Temperature in Celsius: %.2f°C\n", convertedTemperature);
    } else if (choice == 2) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        convertedTemperature = celsiusToFahrenheit(temperature);
        printf("Temperature in Fahrenheit: %.2f°F\n", convertedTemperature);
    } else {
        printf("Invalid choice! Please run the program again.\n");
    }

    return 0;
}
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 /9;
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}
