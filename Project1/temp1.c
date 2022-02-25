#include<stdio.h>

int main() {
	int a, b, c;
	int temp = 0;
	int result=0;

	scanf("%d %d %d", &a, &b, &c);

	if (a == b&& b == c) {
		result = 10000 + a * 1000;
	}
	else if (a == b || b == c || c == a ) {

		if (a == b)
			temp = a;
		else if (b == c)
			temp = b;
		else
			temp = c;
		result = 1000 + temp * 100;
	}
	else {
		temp = a;
		if (temp < b)
			temp = b;
		if (temp < c)
			temp = c;
		result = temp * 100;
	}

	printf("%d", result);
}