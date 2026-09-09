#include<stdio.h>
 #include<time.h>
void Normal() {
for (int i = 0; i < 10; i++) {
printf("Hello\n");
}
}

void Unrolled() {
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
clock_t start, end;
double time_normal, time_unrolled;

start = clock();
Normal();
end = clock();
time_normal = (double)(end - start) / CLOCKS_PER_SEC;
printf("Normal Loop Time: %f seconds\n", time_normal);

printf("\n-----------------------------------------\n\n");

start = clock();
Unrolled();
end = clock();
time_unrolled = (double)(end - start) / CLOCKS_PER_SEC;
printf("Unrolled Loop Time: %f seconds\n", time_unrolled);

printf("\n-----------------------------------------\n\n");
if (time_unrolled < time_normal) {
printf("Conclusion: Unrolled loop is faster.\n");
} else {
printf("Conclusion: Normal loop is faster.\n");
}
return 0;
}

