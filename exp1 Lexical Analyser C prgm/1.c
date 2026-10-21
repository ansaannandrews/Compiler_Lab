#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] ={"int", "float", "return"};

int iskeyword(char str[]) {
	int n = sizeof(keywords)/sizeof(keywords[0]);
	for(int i = 0;i < n;i++) {
		if(strcmp(str,keywords[i]) == 0)
			return 1;
	}
	return 0;
}

int main() {
	FILE *fp;
	char ch, buffer[100];
	int i;
	
	fp = fopen("input.txt","r");
	
	if(fp == NULL) {
		printf("Can't open file\n");
		return 0;
	}
	
	while((ch=fgetc(fp)) != EOF) {
		if(isspace(ch))
			continue;
		if(ch == '/') {
			char next = fgetc(fp);
			if(next == '/') {
				while((ch=fgetc(fp)) != '\n' && ch != EOF);
				continue;
			}
			else if(next == '*') {
				char prev = 0;
				while((ch=fgetc(fp)) != EOF) {
					if(prev == '*' && ch == '/')
						break;
					prev = ch;
				}
				continue;
			}
			else {
				ungetc(next,fp);
				printf("%-10s\tOperator\n","/");
				continue;
		        }
        	}
        	
        	if(isalpha(ch) || ch == '_') {
        		i = 0;
        		buffer[i++] = ch;
        		
        		while((ch=fgetc(fp)) != EOF && (isalnum(ch) || ch == '_'))
        			buffer[i++] = ch;
        			
        		buffer[i] = '\0';
        		
        		if(ch != EOF)
        			ungetc(ch,fp);
        		
        		if(iskeyword(buffer))
        			printf("%-10s\tKeyword\n",buffer);
        		else
        			printf("%-10s\tIdentifier\n",buffer);
        	}
        	
        	else if(isdigit(ch)) {
        		i = 0;
        		buffer[i++] = ch;
        		
        		while((ch=fgetc(fp)) != EOF && (isdigit(ch) || ch == '.'))
        			buffer[i++] = ch;
        			
        		buffer[i] = '\0';
        		
        		if(ch != EOF)
        			ungetc(ch,fp);
        		
        		printf("%-10s\tConstant\n",buffer);
        	}
        	
        	else if(strchr("+-*=<>!%&|",ch)) {
        		char op[3];
        		op[0] = ch;
        		op[1] = '\0';
        		
        		char next = fgetc(fp);
        		
        		if((ch == '=' && next == '=') ||
        		(ch == '!' && next == '=') ||
        		(ch == '<' && next == '=') ||
        		(ch == '>' && next == '=') ||
        		(ch == '+' && next == '+') ||
        		(ch == '-' && next == '-') ||
        		(ch == '&' && next == '&') ||
        		(ch == '|' && next == '|')) {
        			op[1] = next;
        			op[2] = '\0';
        		}
        		else {
        			if(next != EOF)
        				ungetc(next,fp);
        		}
        		
        		printf("%-10s\tOperator\n",op);
        	} 
        	
        	else if(strchr("()[]{},;",ch)) {
        		printf("%c\tDelimiter\n",ch);
        	}
	}
	
	fclose(fp);
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
