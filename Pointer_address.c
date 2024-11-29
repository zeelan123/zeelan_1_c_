#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;  

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);

    *ptr = 20;  
    printf("New value of num: %d\n", num);

    return 0;
}
