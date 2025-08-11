#include <stdio.h>
#include <stdlib.h>

#define N 20  // Maximum queue size (we will use indices 1 to N for circular logic)

int Q[N + 1];  // Queue array (N+1 because index 0 is unused to make circular logic easier)
int F = 0, R = 0;  // F = Front index, R = Rear index

// Insert element into circular queue
void Enqueue(int Y) {
    // Step 1: Move rear forward (with wrap-around)
    if (R == N) 
        R = 1;      // If R was at last position, wrap to first position
    else 
        R = R + 1;  // Otherwise, just move forward
    
    // Step 2: Check overflow (queue is full if front == rear after move)
    if (F == R) {  
        printf("Queue Overflow\n");
        
        // Undo the rear move (to keep queue unchanged)
        if (R == 1) 
            R = N;  
        else 
            R = R - 1;
        
        return;  // Stop insertion
    }

    // Step 3: Store the element at the rear position
    Q[R] = Y;

    // Step 4: If this is the first insert, set front to 1
    if (F == 0) 
        F = 1;

    printf("Inserted: %d\n", Y);
}

// Remove element from circular queue
int Dequeue() {
    int Y;

    // Step 1: Check underflow (queue is empty if F == 0)
    if (F == 0) {  
        printf("Queue Underflow\n");
        return -1;
    }

    // Step 2: Take the element at the front
    Y = Q[F];

    // Step 3: Update front position
    if (F == R)  
        F = R = 0;        // If only one element was there, reset to empty state
    else if (F == N) 
        F = 1;            // Wrap around if front was at last position
    else 
        F = F + 1;        // Otherwise, move forward

    printf("Deleted: %d\n", Y);
    return Y;
}

// Display elements in the circular queue
void Display() {
    if (F == 0) {  // Queue empty
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = F;
    while (1) {
        printf("%d ", Q[i]);
        
        // Stop when we have printed the last element (rear)
        if (i == R) 
            break;

        // Move forward with wrap-around
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
