#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N=0;
	int a, b;
	int result = -1;
	int tmp = 0;
	int time=0;
	scanf("%d", &N);

	a = N / 10;
	b = N % 10;

	while (N != result) {

		tmp = a + b;
		result = 10 * b + (tmp % 10);
	

		a = result / 10;
		b = result % 10;

		time++;
	}

	printf("%d", time);
	return 0;
}