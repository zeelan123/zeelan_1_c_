#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; 

    printf("Array elements using pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i + 1, *(ptr + i));
    }

    return 0;
}
