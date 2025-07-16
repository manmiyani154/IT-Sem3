#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;

void insertFront(int val) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = head;
    head = temp;
}

void insertEnd(int val) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return;
    }
    struct Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

void insertSorted(int val) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = val;
    if (head == NULL || val < head->data) {
        temp->next = head;
        head = temp;
        return;
    }
    struct Node* p = head;
    while (p->next && p->next->data < val) p = p->next;
    temp->next = p->next;
    p->next = temp;
}

void deleteFirst() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteBefore(int pos) {
    if (pos <= 2 || head == NULL || head->next == NULL) return;
    struct Node *prev = NULL, *curr = head;
    for (int i = 1; i < pos - 1 && curr->next; i++) {
        prev = curr;
        curr = curr->next;
    }
    if (prev) {
        prev->next = curr->next;
        free(curr);
    }
}

void deleteAfter(int pos) {
    struct Node* p = head;
    for (int i = 1; i < pos && p; i++) p = p->next;
    if (p && p->next) {
        struct Node* temp = p->next;
        p->next = temp->next;
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

    insertSorted(30);
    insertSorted(10);
    insertSorted(20);
    insertEnd(40);
    insertFront(5);
    display();
    deleteFirst();
    deleteBefore(3);
    deleteAfter(2);
    display();
    return 0;
}
