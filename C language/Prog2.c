#include <stdio.h>

struct Student {
    int id;
    char name[20];
    char dept[10];
    float percent;
};

int main() {

    struct Student s1 = {1, "A", "IT", 85.5};
    struct Student s2 = {2, "B", "IT", 91.0};

    struct Student *ptr;

    ptr = &s1;
    printf("ID: %d, Name: %s, Dept: %s, %%: %.2f\n", ptr->id, ptr->name, ptr->dept, ptr->percent);

    ptr = &s2;
    printf("ID: %d, Name: %s, Dept: %s, %%: %.2f\n", ptr->id, ptr->name, ptr->dept, ptr->percent);

    return 0;
}
