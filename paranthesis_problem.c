#include<stdio.h>
#include<string.h>
#define max 100
char stack[max];
int top =-1 ;

void push(char ch)
{
if (top==max-1)
{
 printf("stack is full");
}
else
{
top++;
stack[top]=ch;

}
}
char pop()
{
    char ch;
    ch=stack[top];
    top--;
    return ch;
}
int ismatching(char left ,char right)
{
    if (left=='(' && right==')')
    {
        return 1;
    }
    else if (left=='{' && right=='}')
    {
        return 1;
    }
    else if (left=='[' && right==']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[100];
    printf("please enter the expression:-");
    scanf("%s",exp);
    for(int i=0;i<strlen(exp);i++)
    {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            push(exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
        {
            if(top==-1)
            {
                printf("Invalid expression and stack is empty\n");
                return 0;
            }
            else
            {
                char popped=pop();
                if(!ismatching(popped,exp[i]))
                {
                        printf("invalid_expression\n");
                        return 0;
                }
            }
        }
    }
    if(top==-1)
    {
        printf("valid_Expression\n");

    }
    else
    {
        printf("Invalid expression\n");
    }
    return 0;
}


