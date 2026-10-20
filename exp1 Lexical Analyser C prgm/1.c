#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] = {
    "int", "float", "char", "double", "if", "else",
    "while", "for", "return", "void", "break",
    "continue", "do", "switch", "case", "default",
    "long", "short", "unsigned", "signed", "const"
};

int isKeyword(char str[])
{
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    FILE *fp;
    char ch, buffer[100];
    int i;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("Cannot open input file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        // Ignore white spaces
        if (isspace(ch))
            continue;

        // Skip single-line comments
        if (ch == '/')
        {
            char next = fgetc(fp);

            if (next == '/')
            {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            }
            else if (next == '*')
            {
                char prev = 0;
                while ((ch = fgetc(fp)) != EOF)
                {
                    if (prev == '*' && ch == '/')
                        break;
                    prev = ch;
                }
                continue;
            }
            else
            {
                ungetc(next, fp);
                printf("/\t\tOperator\n");
                continue;
            }
        }

        // Identifier or Keyword
        if (isalpha(ch) || ch == '_')
        {
            i = 0;
            buffer[i++] = ch;

            while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_'))
                buffer[i++] = ch;

            buffer[i] = '\0';

            if (ch != EOF)
                ungetc(ch, fp);

            if (isKeyword(buffer))
                printf("%-10s\tKeyword\n", buffer);
            else
                printf("%-10s\tIdentifier\n", buffer);
        }

        // Number
        else if (isdigit(ch))
        {
            i = 0;
            buffer[i++] = ch;

            while ((ch = fgetc(fp)) != EOF && (isdigit(ch) || ch == '.'))
                buffer[i++] = ch;

            buffer[i] = '\0';

            if (ch != EOF)
                ungetc(ch, fp);

            printf("%-10s\tNumber\n", buffer);
        }

        // Operators
        else if (strchr("+-*=<>!%&|", ch))
        {
            char op[3];
            op[0] = ch;
            op[1] = '\0';

            char next = fgetc(fp);

            if ((ch == '=' && next == '=') ||
                (ch == '!' && next == '=') ||
                (ch == '<' && next == '=') ||
                (ch == '>' && next == '=') ||
                (ch == '+' && next == '+') ||
                (ch == '-' && next == '-') ||
                (ch == '&' && next == '&') ||
                (ch == '|' && next == '|'))
            {
                op[1] = next;
                op[2] = '\0';
            }
            else
            {
                if (next != EOF)
                    ungetc(next, fp);
            }

            printf("%-10s\tOperator\n", op);
        }

        // Delimiters
        else if (strchr("(){}[],;", ch))
        {
            printf("%c\t\tDelimiter\n", ch);
        }
    }

    fclose(fp);

    return 0;
}
