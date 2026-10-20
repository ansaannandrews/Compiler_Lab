#include <stdio.h>
#include <time.h>

void OrginalPrgm() {
	int a = 5;
	int b = 10;
	int c = a + b;
	printf("Result = %d\n",c);
}	
	
void OptimizedPrgm() {
	int c = 5 + 10;
	printf("Result = %d\n",c);
}	
	
int main() {
	clock_t start, end;
	double timeorginal, timeoptimized;
	
	start = clock();
	OrginalPrgm();
	end = clock();
	timeorginal = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time of Orginal Program = %fseconds\n\n",timeorginal);
	
	start = clock();
	OptimizedPrgm();
	end = clock();
	timeoptimized = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time of Optimized Program = %fseconds\n\n\n",timeoptimized);
	
	if(timeoptimized < timeorginal)
		printf("CONCLUSION: Optimized program is FasteR\n");
	else if(timeoptimized > timeorginal)
		printf("CONCLUSION: Normal program is FasteR\n");
	else
		printf("CONCLUSION: BOth program has eQual excecution Time\n");
	return 0;
}




