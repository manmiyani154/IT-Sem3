#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;  

    // ---------- malloc ----------
    // malloc() allocates memory but does NOT initialize it
    arr = (int *)malloc(3 * sizeof(int));  // Allocate space for 3 integers
    if (arr == NULL) {
        printf("Memory allocation failed (malloc)\n");
        return 1;
    }
    arr[0] = 10; arr[1] = 20; arr[2] = 30;  // Assign values
    printf("malloc(): %d %d %d\n", arr[0], arr[1], arr[2]);

    // ---------- calloc ----------
    // calloc() allocates memory AND initializes all bytes to 0
    int *cArr = (int *)calloc(3, sizeof(int));  // Allocate space for 3 integers
    if (cArr == NULL) {
        printf("Memory allocation failed (calloc)\n");
        return 1;
    }
    printf("calloc(): %d %d %d\n", cArr[0], cArr[1], cArr[2]);  // All should be 0

    // ---------- realloc ----------
    // realloc() changes the size of already allocated memory
    arr = (int *)realloc(arr, 5 * sizeof(int));  // Increase size to 5 integers
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }
    arr[3] = 40; arr[4] = 50;  // Assign new values
    printf("realloc(): ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    // ---------- free ----------
    // free() releases allocated memory to avoid memory leaks
    free(arr);
    free(cArr);

    return 0;
}
