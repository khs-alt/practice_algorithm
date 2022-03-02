#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num;
	int score[1001];
	int big = -1;
	int total=0;

	scanf("%d", &num);
	
		for (int i = 0; i < num; ++i) {
			scanf("%d", &score[i]);
			if (big < score[i])
				big = score[i];
			total = total + score[i];
		}
		printf("%f", (double)total / (double)big * 100 / num);
		total = 0;
		big = -1;
		

	return 0;
}