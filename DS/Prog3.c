#include <stdio.h>

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++){
        printf("Enter %d element:", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 10; i++) printf("\nThe address of arr[%d] using &: %X",i,&arr[i]);
    
    printf("\n----------");
    printf("\nThe Base address for arr[0]: %X",&arr[0]);
    for (int i = 1; i < 10; i++) printf("\nThe address of arr[%d] using Base Address: %X",i,&arr[0 + i]);
    
    printf("\n----------");
    printf("\nThe Base address for arr[0]: %X",&arr[0]);
    for (int i = 1; i < 10; i++) printf("\nThe address of arr[%d] using formula: %X",i,&arr[0 + i] + sizeof(int));
    return 0;
}
