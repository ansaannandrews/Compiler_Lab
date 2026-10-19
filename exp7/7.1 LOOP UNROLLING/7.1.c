#include <stdio.h>
#include <time.h>

void normal() {
	for(int i = 0; i <= 9; i++) {
		printf("Hello\n");
} }

void unrolled() {
	printf("Hello\n");
	printf("Hello\n");
	printf("Hello\n");
	printf("Hello\n");
	printf("Hello\n");
	printf("Hello\n");
	printf("Hello\n");
	printf("Hello\n");
	printf("Hello\n");
	printf("Hello\n");
}

int main() {
	clock_t start,end;
	double time_normal, time_unrolled;
	
	start = clock();
	normal();
	end = clock();
	
	time_normal = (double)(end-start)/CLOCKS_PER_SEC;
	printf("Normal Loop Excecution Time = %f\n\n",time_normal);
	
	start = clock();
	unrolled();
	end = clock();
	
	time_unrolled = (double)(end-start)/CLOCKS_PER_SEC;
	printf("Unrolled Loop Excecution Time = %f\n",time_unrolled);
	
	if(time_unrolled < time_normal)
		printf("Conclusion: UNROLLED LOOP FASTER\n");
	else
		printf("Conclusion: NORMAL LOOP FASTER\n");
}
	
	
	
	
	
	
	
	
	
	
