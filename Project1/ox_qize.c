#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num;
	char str[81];
	int score = 0;
	int total_score = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; ++i) {
		scanf("%s", &str);
		for (int j = 0; j < 81; j++) {
			if (str[j] == 'O') {
				score += 1;
			}
			else if (str[j] == 'X') {
				score = 0;
			}
			else
				break;
			total_score = total_score + score;
		}
		
		printf("%d \n", total_score);
		total_score = 0;
		score = 0;
	}
}