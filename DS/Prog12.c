#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

void insertFront(int val) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = val;
    temp->prev = NULL;
    temp->next = head;
    if (head) head->prev = temp;
    head = temp;
}

void insertEnd(int val) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        return;
    }
    struct Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
    temp->prev = p;
}

void deleteLast() {
    if (head == NULL) return;
    struct Node* p = head;
    while (p->next) p = p->next;
    if (p->prev) p->prev->next = NULL;
    else head = NULL;
    free(p);
}

void deleteBefore(int pos) {
    if (pos <= 1 || head == NULL) return;
    struct Node* p = head;
    for (int i = 1; i < pos - 1 && p; i++) p = p->next;
    if (p && p->prev) {
        struct Node* temp = p->prev;
        if (temp->prev) temp->prev->next = p;
        else head = p;
        p->prev = temp->prev;
        free(temp);
    }
}

void display() {
    struct Node* p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {

    insertFront(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    display();
    deleteLast();
    deleteBefore(3);
    display();
    return 0;
}
