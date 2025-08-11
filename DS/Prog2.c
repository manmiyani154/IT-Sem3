#include <stdio.h>

struct Student {
    int id;             
    char name[20];       
    float percent;
    int marks[3];        // Array within structure (for 3 subjects)
};

int main() {
    // ---------- 1. Structure variable ----------
    struct Student s1 = {1, "Alice", 85.5, {90, 88, 78}}; // Initializing array inside structure

    // ---------- 2. Structure pointer ----------
    struct Student *ptr = &s1; // Pointer to structure
    printf("Pointer Access: ID=%d, Name=%s, %%=%.1f\n",
           ptr->id, ptr->name, ptr->percent);

    // ---------- 3. Array of structures ----------
    struct Student arr[2] = {
        {2, "Bob", 91.0, {95, 89, 92}},
        {3, "Charlie", 78.5, {80, 77, 79}}
    };
    printf("Array of Structures:\n");
    for (int i = 0; i < 2; i++)
        printf("%d %s %.1f\n", arr[i].id, arr[i].name, arr[i].percent);

    // ---------- 4. Array within a structure ----------
    printf("Marks of %s: ", s1.name);
    for (int i = 0; i < 3; i++)
        printf("%d ", s1.marks[i]);
    printf("\n");

    return 0;
}
