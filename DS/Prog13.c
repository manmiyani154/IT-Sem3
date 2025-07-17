#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int val) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = val;
    if (head == NULL) {
        head = temp;
        temp->next = head;
        return;
    }
    struct Node* p = head;
    while (p->next != head) p = p->next;
    p->next = temp;
    temp->next = head;
}

void insertBefore(int pos, int val) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = val;
    if (pos == 1 || head == NULL) {
        temp->next = head;
        struct Node* p = head;
        if (p != NULL) {
            while (p->next != head) p = p->next;
            p->next = temp;
        }
        head = temp;
        temp->next = head;
        return;
    }
    struct Node* p = head;
    for (int i = 1; i < pos - 1 && p->next != head; i++) p = p->next;
    temp->next = p->next;
    p->next = temp;
}

void deleteFirst() {
    if (head == NULL) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* p = head;
    while (p->next != head) p = p->next;
    struct Node* temp = head;
    head = head->next;
    p->next = head;
    free(temp);
}

void deleteAfter(int pos) {
    if (head == NULL) return;
    struct Node* p = head;
    for (int i = 1; i < pos && p->next != head; i++) p = p->next;
    struct Node* temp = p->next;
    if (temp == head) head = head->next;
    p->next = temp->next;
    free(temp);
}

void display() {
    if (head == NULL) return;
    struct Node* p = head;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertBefore(2, 15);
    display();
    deleteFirst();
    deleteAfter(2);
    display();
    return 0;
}
