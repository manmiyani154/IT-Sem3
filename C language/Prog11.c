#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void insert(int val) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void delete() {
    if (front == NULL) return;
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display() {
    struct Node* temp = front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    insert(1);
    insert(2);
    insert(3);
    display();
    delete();
    display();
    return 0;
}
