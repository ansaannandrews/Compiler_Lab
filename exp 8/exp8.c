#include<stdio.h>
#include<string.h>
char op[2], arg1[10], arg2[10], result[10];

int main()
{
FILE *fp1, *fp2;
char f[100];

printf("Enter input file name: ");
scanf("%99s", f);

fp1 = fopen(f, "r");
if (fp1 == NULL)
{
printf("Unable to open input file.\n");
return 1;
}

fp2 = fopen("output.txt", "w");
if (fp2 == NULL)
{
printf("Unable to create output file.\n");
fclose(fp1);
return 1;
}

while (fscanf(fp1, "%s %s %s %s", op, arg1, arg2, result) == 4)
{
if (strcmp(op, "+") == 0)
{
fprintf(fp2, "MOV AX, %s\n", arg1);
fprintf(fp2, "ADD AX, %s\n", arg2);
fprintf(fp2, "MOV %s, AX\n\n", result);
}
else if (strcmp(op, "*") == 0)
{
fprintf(fp2, "MOV AX, %s\n", arg1);
fprintf(fp2, "MUL %s\n", arg2);
fprintf(fp2, "MOV %s, AX\n\n", result);
}
else if (strcmp(op, "-") == 0)
{
fprintf(fp2, "MOV AX, %s\n", arg1);
fprintf(fp2, "SUB AX, %s\n", arg2);
fprintf(fp2, "MOV %s, AX\n\n", result);
}
else if (strcmp(op, "/") == 0)
{
fprintf(fp2, "MOV AX, %s\n", arg1);
fprintf(fp2, "MOV DX, 0\n");
fprintf(fp2, "DIV %s\n", arg2);
fprintf(fp2, "MOV %s, AX\n\n", result);
}
else if (strcmp(op, "=") == 0)
{
fprintf(fp2, "MOV AX, %s\n", arg1);
fprintf(fp2, "MOV %s, AX\n\n", result);
}
}

fclose(fp1);
fclose(fp2);

printf("Target code generated successfully in output.txt\n");

return 0;
}
