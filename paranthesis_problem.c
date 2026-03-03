#include<stdio.h>
#include<string.h>

#define max 100   // Maximum size of stack

// Stack array to store brackets
char stack[max];

// 'top' keeps track of the top element of stack
int top = -1;

// -------------------- PUSH FUNCTION --------------------
// This function inserts an element into the stack
void push(char ch)
{
    // Check for stack overflow
    if (top == max - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;              // Move top one position up
        stack[top] = ch;    // Insert element at top
    }
}


// -------------------- POP FUNCTION --------------------
// This function removes and returns top element from stack
char pop()
{
    char ch;

    ch = stack[top];   // Store top element
    top--;             // Decrease top (remove element)

    return ch;         // Return removed element
}


// -------------------- MATCHING FUNCTION --------------------
// This function checks whether opening and closing brackets match
int ismatching(char left, char right)
{
    if (left == '(' && right == ')')
        return 1;

    else if (left == '{' && right == '}')
        return 1;

    else if (left == '[' && right == ']')
        return 1;

    else
        return 0;   // If not matching
}


// -------------------- MAIN FUNCTION --------------------
int main()
{
    char exp[100];

    printf("Please enter the expression: ");
    scanf("%s", exp);

    // Traverse each character of the expression
    for (int i = 0; i < strlen(exp); i++)
    {
        // If opening bracket, push into stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }

        // If closing bracket
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            // If stack is empty → no matching opening bracket
            if (top == -1)
            {
                printf("Invalid Expression (Stack is empty)\n");
                return 0;
            }
            else
            {
                // Pop the top element
                char popped = pop();

                // Check if popped bracket matches current bracket
                if (!ismatching(popped, exp[i]))
                {
                    printf("Invalid Expression (Brackets not matching)\n");
                    return 0;
                }
            }
        }
    }

    // After checking complete expression
    // If stack is empty → expression is valid
    if (top == -1)
    {
        printf("Valid Expression\n");
    }
    else
    {
        // If stack still has elements → some brackets not closed
        printf("Invalid Expression (Unclosed brackets)\n");
    }

    return 0;
}