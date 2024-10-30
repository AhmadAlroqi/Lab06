#include <stdio.h>
#include <stdlib.h>

int* push(int *stack, int *top, int *size, int value);
int pop(int *stack, int *top);
void display(int *stack, int top);

int main() {
    int *stack = NULL;
    int top = -1, size = 0, value;
    char command;

    do {
        printf("Enter a command (p = push, o= pop, d = display, e = exit): ");
        scanf(" %c", &command);

        if (command == 'p') {  
            printf("Enter an integer to push: ");
            scanf("%d", &value);
            stack = push(stack, &top, &size, value);

        } else if (command == 'o') {  
            pop(stack, &top);

        } else if (command == 'd') { 
            display(stack, top);
        }
    } while (command != 'e');  

    free(stack);
    return 0;
}

int* push(int *stack, int *top, int *size, int value) {
    (*size)++;
    stack = (int*) realloc(stack, (*size) * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack[++(*top)] = value;
    return stack;
}

int pop(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack is empty.\n");
        return -1; 
    } else {
        printf("Popped value: %d\n", stack[*top]);
        (*top)--;
        return 0; 
    }
}

void display(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Current stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

