#include <stdio.h>

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {

    int a[100], n, key, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &key);

    int result = binarySearch(a, n, key);
    if (result != -1) printf("Found at index %d\n", result);
    else printf("Not found\n");
    return 0;
}
