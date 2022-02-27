#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N=0;
	int a, b;
	int result = -1;
	int tmp = 0;
	int time=0;
	scanf("%d", &N);

	while (N != result) {

		a = N / 10;
		b = N % 10;

		tmp = a + b;
		result = 10 * a + (tmp % 10);
		time++;
	}

	printf("%d", time);
	return 0;
}