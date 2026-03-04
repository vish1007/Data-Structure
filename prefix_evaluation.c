#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Push function */
void push(int value)
{
    top++;
    stack[top] = value;
}

/* Pop function */
int pop()
{
    int value;
    value = stack[top];
    top--;
    return value;
}

int main()
{
    char prefix[100];
    int A, B, result;

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    /* Scan prefix expression from right to left */
    for(int i = strlen(prefix) - 1; i >= 0; i--)
    {
        /* If operand push into stack */
        if(isdigit(prefix[i]))
        {
            push(prefix[i] - '0');   // convert character to integer
        }
        /* If operator */
        else
        {
            A = pop();
            B = pop();
            if(prefix[i] == '+')
                result = A + B;
            else if(prefix[i] == '-')
                result = A - B;

            else if(prefix[i] == '*')
                result = A * B;

            else if(prefix[i] == '/')
                result = A / B;

            push(result);
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}