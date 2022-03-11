#include<stdio.h>

int main() {
	int n=0;
	int num = 0;
	scanf_s("%d", &n);

	if (n < 100) {
		printf("%d", n);
		return 0;
	}

	for (int i = 100; i <= n; i++) {
		if ((i % 100) / 10 - i % 10 == i/ 100 - (i % 100) / 10)
			num++;
	}
	printf("%d", num+99);
}