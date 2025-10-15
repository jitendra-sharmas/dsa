#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1)
        printf("\nStack Overflow!");
    else {
        top++;
        stack[top] = val;
        printf("\n%d pushed to stack.", val);
    }
}

void pop() {
    if (top == -1)
        printf("\nStack Underflow!");
    else {
        printf("\n%d popped from stack.", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1)
        printf("\nStack is empty.");
    else {
        printf("\nStack elements are: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
}

void checkPalindrome() {
    char str[50], rev[50];
    int i, len;
    printf("\nEnter a string: ");
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len; i++)
        stack[i] = str[i];
    top = len - 1;
    for (i = 0; i < len; i++)
        rev[i] = stack[top--];
    rev[len] = '\0';
    if (strcmp(str, rev) == 0)
        printf("\n%s is a Palindrome.", str);
    else
        printf("\n%s is not a Palindrome.", str);
}

int main() {
    int choice, val;
    do {
        printf("\n\n--- STACK OPERATIONS ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Check Palindrome");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            checkPalindrome();
            break;
        case 5:
            printf("\nExiting program...");
            break;
        default:
            printf("\nInvalid choice!");
        }
    } while (choice != 5);
    return 0;
}