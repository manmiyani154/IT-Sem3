#include <stdio.h>   // Standard input-output header
#include <stdlib.h>  // Standard library header for exit()

#define N 20  // Maximum size of the queue

int Q[N];     // Array to store queue elements
int F = 0, R = 0;    // Front (F) and Rear (R) pointers

// Function to insert (enqueue) an element into the queue
void Enqueue() {
    int Y;
    printf("Enter value to insert: ");
    scanf("%d", &Y);

    // Check if queue is full
    if (R >= N) {  
        printf("Queue Overflow\n");
        return;
    }

    // Store the value at rear position
    Q[R] = Y;
    ++R; // Move rear pointer forward

    // If front was 0 (empty queue), set it to first position
    if (F == 0) 
        F = 1;  

    printf("Inserted: %d\n", Y);
}

// Function to remove (dequeue) an element from the queue
int Dequeue() {
    int Y;

    // If front is 0, queue is empty
    if (F == 0) {  
        printf("Queue Underflow\n");
        return -1;
    }

    // Take the value at front position (F-1 because array index starts at 0)
    Y = Q[F - 1];

    // If only one element is left, reset pointers after deletion
    if (F == R) 
        F = R = 0;  
    else 
        F = F + 1;  // Move front pointer forward

    printf("Deleted: %d\n", Y);
    return Y;
}

// Function to display all elements in the queue
void Display() {
    if (F == 0) { 
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = F - 1; i < R; i++) 
        printf("%d ", Q[i]);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: Enqueue(); break;
            case 2: Dequeue(); break;
            case 3: Display(); break;
            case 4: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
