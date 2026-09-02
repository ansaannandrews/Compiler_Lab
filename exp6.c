#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push a symbol into stack */
void push(char c)
{
    stack[++top] = c;
}

/* Remove n symbols from stack */
void pop(int n)
{
    top -= n;
}

/* Display stack */
void showStack()
{
    int i;

    for (i = 0; i <= top; i++)
    {
        if (stack[i] == 'i')
            printf("id");
        else
            printf("%c", stack[i]);
    }
}

/* Display input with i shown as id */
void showInput(char input[], int pos)
{
    int i;

    for (i = pos; input[i] != '\0'; i++)
    {
        if (input[i] == 'i')
            printf("id");
        else
            printf("%c", input[i]);
    }
}

/* Find displayed input length */
int inputLength(char input[], int pos)
{
    int i;
    int length = 0;

    for (i = pos; input[i] != '\0'; i++)
    {
        if (input[i] == 'i')
            length += 2;
        else
            length++;
    }

    return length;
}

/* Display one parsing step */
void showStep(char input[], int pos, char action[])
{
    int stackLength = 0;
    int inputLen;

    /* Calculate displayed stack length */
    int i;
    for (i = 0; i <= top; i++)
    {
        if (stack[i] == 'i')
            stackLength += 2;
        else
            stackLength++;
    }

    /* Display stack */
    showStack();

    /* Space between columns */
    printf("%*s", 15 - stackLength, "");

    /* Display input */
    showInput(input, pos);

    /* Calculate displayed input length */
    inputLen = inputLength(input, pos);

    /* Space before action */
    printf("%*s", 15 - inputLen, "");

    printf("%s\n", action);
}

/* Try to reduce the stack */
int reduce(char input[], int pos)
{
    /* id -> F */
    if (top >= 0 && stack[top] == 'i')
    {
        stack[top] = 'F';
        showStep(input, pos, "REDUCE F -> id");
        return 1;
    }

    /* (E) -> F */
    if (top >= 2 &&
        stack[top - 2] == '(' &&
        stack[top - 1] == 'E' &&
        stack[top] == ')')
    {
        pop(3);
        push('F');

        showStep(input, pos, "REDUCE F -> (E)");
        return 1;
    }

    /* T * F -> T */
    if (top >= 2 &&
        stack[top - 2] == 'T' &&
        stack[top - 1] == '*' &&
        stack[top] == 'F')
    {
        pop(3);
        push('T');

        showStep(input, pos, "REDUCE T -> T*F");
        return 1;
    }

    /* E + T -> E */
    if (top >= 2 &&
        stack[top - 2] == 'E' &&
        stack[top - 1] == '+' &&
        stack[top] == 'T')
    {
        pop(3);
        push('E');

        showStep(input, pos, "REDUCE E -> E+T");
        return 1;
    }

    /* F -> T */
    if (top >= 0 && stack[top] == 'F')
    {
        stack[top] = 'T';

        showStep(input, pos, "REDUCE T -> F");
        return 1;
    }

    /*
       T -> E
       Do not reduce if next input is *
    */
    if (top >= 0 &&
        stack[top] == 'T' &&
        input[pos] != '*')
    {
        stack[top] = 'E';

        showStep(input, pos, "REDUCE E -> T");
        return 1;
    }

    return 0;
}

int main()
{
    char input[MAX];
    char temp[MAX];

    int i, j;
    int pos = 0;
    int valid = 1;

    printf("=====================================================\n");
    printf("              SHIFT-REDUCE PARSER\n");
    printf("=====================================================\n\n");

    printf("GRAMMAR:\n");
    printf("E -> E+T | T\n");
    printf("T -> T*F | F\n");
    printf("F -> (E) | id\n\n");

    printf("Enter input string: ");
    scanf("%s", temp);

    /*
       Convert id into single symbol 'i'.

       Example:
       id*id -> i*i
    */
    j = 0;

    for (i = 0; temp[i] != '\0'; i++)
    {
        if (temp[i] == 'i' && temp[i + 1] == 'd')
        {
            input[j++] = 'i';
            i++;
        }
        else
        {
            input[j++] = temp[i];
        }
    }

    input[j++] = '$';
    input[j] = '\0';

    /* Initialize stack */
    push('$');

    printf("\n-----------------------------------------------------\n");
    printf("STACK          INPUT          ACTION\n");
    printf("-----------------------------------------------------\n");

    while (input[pos] != '$')
    {
        /* Check whether input is id */
        if (input[pos] == 'i')
        {
            push('i');
            pos++;

            showStep(input, pos, "SHIFT id");
        }

        /* Check operators and parentheses */
        else if (input[pos] == '+' ||
                 input[pos] == '*' ||
                 input[pos] == '(' ||
                 input[pos] == ')')
        {
            char symbol = input[pos];

            push(symbol);
            pos++;

            if (symbol == '+')
                showStep(input, pos, "SHIFT +");
            else if (symbol == '*')
                showStep(input, pos, "SHIFT *");
            else if (symbol == '(')
                showStep(input, pos, "SHIFT (");
            else
                showStep(input, pos, "SHIFT )");
        }

        /* Invalid character */
        else
        {
            valid = 0;
            break;
        }

        /* Perform all possible reductions */
        while (reduce(input, pos))
        {
            /* Continue reducing */
        }
    }

    /* Perform final reductions */
    while (reduce(input, pos))
    {
        /* Continue reducing */
    }

    printf("-----------------------------------------------------\n");

    /* Acceptance condition */
    if (valid &&
        input[pos] == '$' &&
        top == 1 &&
        stack[0] == '$' &&
        stack[1] == 'E')
    {
        printf("\nSUCCESS: String accepted\n");
    }
    else
    {
        printf("\nFAILURE: String rejected\n");
    }

    printf("=====================================================\n");

    return 0;
}
