#include <stdio.h>
#include <string.h>

#define MAX 20

struct transition {
	char from[10];
	char symbol;
	char to[10];
}t[MAX];

char state[MAX][10];
int n, m;
char visited[MAX];

int getindex(char s[]) {
	int i;
	for(i = 0;i < n;i++) {
		if(strcmp(state[i],s) == 0)
			return i;
	}
	return -1;
}

void eclosure(char state[]) {
	int i;
	int index = getindex(state);
	
	if(index == -1||visited[index])
		return;
		
	visited[index] = 1;
	printf(" %s",state);
	
	for(i = 0;i < m;i++) {
		if(strcmp(t[i].from,state) == 0 && t[i].symbol == 'e')
			eclosure(t[i].to);
	}
	
}
int main() {
	FILE *fp;
	int i;
	
	fp = fopen("input.dat","r");
	
	if(fp ==NULL) {
		printf("Cant open input file\n");
		return 1;
	}
	printf("Enter the number of states: ");
	scanf("%d",&n);
	
	printf("Enter the name of states:\n");
	for(i = 0;i < n;i++) {
		scanf("%s",state[i]);
	}
	
	m = 0;
	while(fscanf(fp,"%s %c %s",t[m].from,&t[m].symbol,t[m].to) != EOF)
		m++;
		
	fclose(fp);
		
	printf("Epsilon Closure of each state = \n");
	for(i = 0;i < n;i++) {
		int j = 0;
		for(j = 0;j < n;j++)
			visited[j] = 0;
		printf("Epsilon-Closure(%s) = {",state[i]);
		eclosure(state[i]);
		printf("}\n");
	}
	return 0;
}	
	
	
	
	
	
	
	
	
	
	
	
	
