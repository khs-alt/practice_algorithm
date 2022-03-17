//#include <stdio.h>
//#include <stdbool.h>
//
//int main() {
//	char str[100] = { 0 };
//	bool is_capital = false, is_lowercase = false, is_number = false, is_special_characters = false;
//	int str_len = 0;
//	scanf_s("%s", &str, 100);
//	int i = 0;
//
//	for (i = 0; str[i] != NULL; i++) {
//		if (str[i] >= 'a' && str[i] <= 'z')is_lowercase = true;
//		else if (str[i] >= 'A' && str[i] <= 'Z')is_capital = true;
//		else if (str[i] >= '0' && str[i] <= '9')is_number = true;
//		else if (str[i] == '!' || str[i] == '?' || str[i] == '*' || str[i] == '#' || str[i] == '$')is_special_characters = true;
//		else return 0;
//	}
//
//	str_len = i;
//
//	if (is_capital == true && is_lowercase == true && is_number == true && is_special_characters == true && str_len >= 10)
//		printf("모든 조건을 만족");
//	else
//		printf("조건을 만족하지 않습니다.");
//	
//}