#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str[100000] = {0};
	//memset(str, 0, sizeof(char)*100000);
	scanf("%[^\n]s", &str);
	int num = 0;
	int i = 0;
	while (str[i] == ' ')
		i++;
	for (; str[i] != NULL; i++){
		if (str[i] == ' ' && str[i+1] != ' ' && str[i+1] != NULL)
			num++;
	}

	printf("%d\n", num+1);
	return 0;
}