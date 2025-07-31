#include <stdio.h>
#include <stdlib.h>

#define N 20  

int Q[N + 1];  
int F = 0, R = 0;  

void Enqueue(int Y) {
    if (R == N) R = 1;  // Wrap around
    else R = R + 1;
    if (F == R) {  /
        printf("Queue Overflow\n");
        if (R == 1) R = N;
        else R = R - 1;
        return;
    }
    Q[R] = Y;
    if (F == 0) F = 1;  // Set front
    printf("Inserted: %d\n", Y);
}

int Dequeue() {
    int Y;
    if (F == 0) {  
        printf("Queue Underflow\n");
        return -1;
    }
    Y = Q[F];
    if (F == R) F = R = 0;  // Reset if last element deleted
    else if (F == N) F = 1;
    else F = F + 1;
    printf("Deleted: %d\n", Y);
    return Y;
}

void Display() {
    if (F == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = F;
    while (1) {
        printf("%d ", Q[i]);
        if (i == R) break;
        i = (i == N) ? 1 : i + 1;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); Enqueue(value); break;
            case 2: Dequeue(); break;
            case 3: Display(); break;
            case 4: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
