#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void insert(int val) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

void delete() {
    if (front == -1 || front > rear) return;
    front++;
}

void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {

    insert(10);
    insert(20);
    insert(30);
    display();       
    delete();
    display();       
    return 0;
}
