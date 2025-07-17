#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, *newArr, *callArr;
    int n, i;

    printf("Enter number of elements (malloc): ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Elements from malloc():\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Demonstrating calloc
    printf("\nEnter number of elements (calloc): ");
    scanf("%d", &n);
    callArr = (int *)calloc(n, sizeof(int));
    if (callArr == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }

    printf("Elements from calloc() (initialized to 0):\n");
    for (i = 0; i < n; i++)
        printf("%d ", callArr[i]);
    printf("\n");

    // Demonstrating realloc
    int newSize;
    printf("\nEnter new size for realloc (increase): ");
    scanf("%d", &newSize);
    newArr = (int *)realloc(arr, newSize * sizeof(int));
    if (newArr == NULL) {
        printf("Reallocation failed\n");
        return 1;
    }

    printf("Enter %d new elements:\n", newSize - n);
    for (i = n; i < newSize; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &newArr[i]);
    }

    printf("Elements after realloc():\n");
    for (i = 0; i < newSize; i++)
        printf("%d ", newArr[i]);
    printf("\n");

    // Freeing all allocated memory
    free(newArr);
    free(callArr);

    return 0;
}
