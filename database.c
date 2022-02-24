#include<stdio.h>

int main() {
	int H = 0, M = 0, time = 1440;
	int t_temp=0;
	
	scanf("%d %d", &H, &M);

	t_temp = (60 * H + M)-45;

	if (t_temp < 0) {
		t_temp = 1440 + t_temp;
	}
	
	H = t_temp / 60;
	M = t_temp % 60;

	printf("%d %d", H, M);
}