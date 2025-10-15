Code 1: Delete from Beginning / End

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* link;
} Node;

Node* start = NULL;

void addAtEnd(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = item;
    if (start == NULL) {
        start = newNode;
        newNode->link = start;
    } else {
        Node* temp = start;
        while (temp->link != start) temp = temp->link;
        temp->link = newNode;
        newNode->link = start;
    }
    printf("Added: %d\n", item);
}

void removeFront() {
    if (start == NULL) {
        printf("List is empty, nothing to remove (front).\n");
        return;
    }
    if (start->link == start) {
        printf("Removed: %d\n", start->val);
        free(start);
        start = NULL;
        return;
    }
    Node* last = start;
    while (last->link != start) last = last->link;
    Node* temp = start;
    printf("Removed: %d\n", temp->val);
    start = start->link;
    last->link = start;
    free(temp);
}

void removeEnd() {
    if (start == NULL) {
        printf("List is empty, nothing to remove (end).\n");
        return;
    }
    if (start->link == start) {
        printf("Removed: %d\n", start->val);
        free(start);
        start = NULL;
        return;
    }
    Node* prev = NULL;
    Node* curr = start;
    while (curr->link != start) {
        prev = curr;
        curr = curr->link;
    }
    printf("Removed: %d\n", curr->val);
    prev->link = start;
    free(curr);
}

void showList() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = start;
    printf("Current List: ");
    do {
        printf("%d ", temp->val);
        temp = temp->link;
    } while (temp != start);
    printf("\n");
}

int main() {
    addAtEnd(11);
    addAtEnd(22);
    addAtEnd(33);
    addAtEnd(44);
    showList();
    removeFront();
    showList();
    removeEnd();
    showList();
    return 0;
}

Output

Errors
1. If list is empty and remove function is called → segmentation fault.
2. Forgetting to update last node pointer when deleting front → circular link breaks.
Code 2: Delete a Given Element

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* link;
} Node;

Node* start = NULL;

void addAtEnd(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = item;
    if (start == NULL) {
        start = newNode;
        newNode->link = start;
    } else {
        Node* temp = start;
        while (temp->link != start) temp = temp->link;
        temp->link = newNode;
        newNode->link = start;
    }
}

void showList() {
    if (start == NULL) { printf("List is empty.\n"); return; }
    Node* t = start;
    printf("List: ");
    do { printf("%d ", t->val); t = t->link; } while (t != start);
    printf("\n");
}

void deleteByValue(int key) {
    if (start == NULL) {
        printf("List empty, %d not found.\n", key);
        return;
    }
    if (start->link == start) {
        if (start->val == key) {
            printf("Deleted: %d\n", key);
            free(start);
            start = NULL;
        } else {
            printf("%d not found.\n", key);
        }
        return;
    }
    if (start->val == key) {
        Node* last = start;
        while (last->link != start) last = last->link;
        Node* temp = start;
        start = start->link;
        last->link = start;
        printf("Deleted: %d\n", temp->val);
        free(temp);
        return;
    }
    Node* prev = start;
    Node* cur  = start->link;
    while (cur != start && cur->val != key) {
        prev = cur;
        cur  = cur->link;
    }
    if (cur == start) {
        printf("%d not found.\n", key);
    } else {
        prev->link = cur->link;
        printf("Deleted: %d\n", key);
        free(cur);
    }
}

int main() {
    addAtEnd(5);
    addAtEnd(15);
    addAtEnd(25);
    addAtEnd(35);
    showList();
    deleteByValue(25);
    showList();
    deleteByValue(5);
    showList();
    deleteByValue(100);
    showList();
    return 0;
}

Output

Errors
1. Forgetting to check for single node case → dangling pointer.
2. If key not found and not handled → infinite loop.
Code 3: Display & Insert (Mandatory)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* link;
} Node;

Node* start = NULL;

void addAtEnd(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = item;
    if (start == NULL) {
        start = newNode;
        newNode->link = start;
    } else {
        Node* t = start;
        while (t->link != start) t = t->link;
        t->link = newNode;
        newNode->link = start;
    }
    printf("Inserted: %d\n", item);
}

void showList() {
    if (start == NULL) { printf("List: (empty)\n"); return; }
    Node* t = start;
    printf("List: ");
    do { printf("%d ", t->val); t = t->link; } while (t != start);
    printf("\n");
}

int main() {
    addAtEnd(10);
    addAtEnd(20);
    addAtEnd(30);
    showList();
    addAtEnd(40);
    showList();
    addAtEnd(50);
    showList();
  