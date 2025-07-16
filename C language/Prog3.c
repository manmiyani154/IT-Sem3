#include <stdio.h>

int main() {

    int arr[10];
    for (int i = 0; i < 10; i++)
        printf("Address of arr[%d] = %p\n", i, (void*)&arr[i]);

    return 0;
}
