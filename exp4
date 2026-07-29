#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct
{
    char from[10];
    char symbol;
    char to[10];
} Transition;

Transition t[MAX];
char states[MAX][10];
int n, m;
int visited[MAX];

// Find index of a state
int getIndex(char state[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(states[i], state) == 0)
            return i;
    }
    return -1;
}

// Recursive function to find epsilon closure
void eClosure(char state[])
{
    int i;
    int index = getIndex(state);

    if (visited[index])
        return;

    visited[index] = 1;
    printf("%s ", state);

    for (i = 0; i < m; i++)
    {
        if (strcmp(t[i].from, state) == 0 && t[i].symbol == 'e')
        {
            eClosure(t[i].to);
        }
    }
}

int main()
{
    FILE *fp;
    int i;

    fp = fopen("input.dat", "r");

    if (fp == NULL)
    {
        printf("Cannot open input.dat\n");
        return 0;
    }

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter state names:\n");
    for (i = 0; i < n; i++)
        scanf("%s", states[i]);

    // Read transitions
    m = 0;
    while (fscanf(fp, "%s %c %s", t[m].from, &t[m].symbol, t[m].to) != EOF)
    {
        m++;
    }

    fclose(fp);

    printf("\nEpsilon Closures:\n");

    for (i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
            visited[j] = 0;

        printf("ε-Closure(%s) = { ", states[i]);
        eClosure(states[i]);
        printf("}\n");
    }

    return 0;
}
