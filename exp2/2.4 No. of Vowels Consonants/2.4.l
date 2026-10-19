%{
#include<stdio.h>
int vowel = 0,consts = 0;
%}

%%
[AEIOUaeiou] {vowel++;}
[A-Za-z] {consts++;}
%%

int yywrap() {
        return 1;
}

int main() {
        printf("Enter the text: \n");
        yylex();
        
        printf("\nNumberof Vowels: %d\n",vowel);
        printf("Numberof Consonants: %d\n",consts);
        return 0;
}
