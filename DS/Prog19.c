#include <stdio.h>

void queueSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {

    int a[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    queueSort(a, n);

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
