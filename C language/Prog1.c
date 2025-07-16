#include <stdio.h>

void swapValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapValue: a = %d, b = %d\n", a, b);
}

void swapReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int x = 5, y = 10;
    printf("Original: x = %d, y = %d\n", x, y);
    swapValue(x, y);
    printf("After swapValue: x = %d, y = %d\n", x, y);

    swapReference(&x, &y);
    printf("After swapReference: x = %d, y = %d\n", x, y);

    return 0;
}
