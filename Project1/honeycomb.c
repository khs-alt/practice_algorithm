#include<stdio.h>

int main() {
	int num=0;
	int i = 0;
	scanf_s("%d", &num);
	if (num == 1) {
		printf("%d", 1);
		return 0;
	}
	num = num - 1;
	while (num > 0) {
		num = num - 6 * i;
		i++;
	}

	printf("%d", i);
}