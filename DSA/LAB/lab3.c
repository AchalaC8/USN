#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 // Maximum size of stack

int stack[MAX];
int top = -1;

// Function prototypes
void push(int);
int pop();
void display();
void checkPalindrome();
void isOverflow();
void isUnderflow();

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n---- STACK MENU ----\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow / Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            value = pop();
            if (value != -1)
                printf("Popped Element: %d\n", value);
            break;

        case 3:
            checkPalindrome();
            break;

        case 4:
            isOverflow();
            isUnderflow();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    }
    return stack[top--];
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

void checkPalindrome()
{
    char str[50];
    char rev[50];
    int i;

    printf("Enter a string to check palindrome: ");
    scanf("%s", str);

    int len = strlen(str);
    int tempTop = -1; // Temporary top for character stack
    char tempStack[50];

    // Push characters to temp stack
    for (i = 0; i < len; i++)
        tempStack[++tempTop] = str[i];

    // Pop characters to form reversed string
    for (i = 0; i < len; i++)
        rev[i] = tempStack[tempTop--];
    rev[i] = '\0';

    if (strcmp(str, rev) == 0)
        printf("The string '%s' is a PALINDROME.\n", str);
    else
        printf("The string '%s' is NOT a palindrome.\n", str);
}

void isOverflow()
{
    // Overflow check
    if (top == MAX - 1)
    {
        printf("Overflow occurs! Stack is full.\n");
    }
    else
    {
        printf("No overflow.\n");
    }
}

void isUnderflow()
{
    // Underflow check
    if (top == -1)
    {
        printf("Underflow occurs! Stack is empty.\n");
    }
    else
    {
        printf("No underflow.\n");
    }
}
