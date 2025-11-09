#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("\nQueue Overflow!");
        return;
    }
    printf("\nEnter the element to insert: ");
    scanf("%d", &item);

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = item;
    printf("\nInserted Successfully!\n");
}

void delete() {
    if (front == -1) {
        printf("\nQueue Underflow!");
        return;
    }
    printf("\nDeleted Element: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("\nQueue is Empty\n");
        return;
    }

    printf("\nCircular Queue Elements: ");
    for (i = front; i != rear; i = (i + 1) % MAX) {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[i]);
}

int main() {
    int choice;
    do {
        printf("\nMENU\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("\nExiting...\n"); break;
            default: printf("\nInvalid Choice!");
        }
    } while (choice != 4);

    return 0;
}
