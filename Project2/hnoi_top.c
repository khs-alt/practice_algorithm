#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num = 0;
	scanf("%d", &num);
	printf("%d", hnoi(num));
}

int hnoi(int n) {
	if (n == 1)return 1;
	return 2*(hnoi(n - 1)) + 1;
}