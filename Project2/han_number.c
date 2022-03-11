#include<stdio.h>

int main() {
	int a[1000] = { 0 };
	int n=0;
	int num = 0;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		if (a[i] % 10 - (a[i] % 100) / 10 == a[i] / 100 - (a[i] % 100) / 10);num++;
	}
	printf("%d", num);
}