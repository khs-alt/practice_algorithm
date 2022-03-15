#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include <windows.h>

typedef struct Complex_number
{
	int real_number;
	int imaginary_number;
}Complex_number;

void checking_string();
void calculate_sum_of_complex_number();
void sum(Complex_number* n, int i, int m, int k);
void calculate_string_length();
void binary_search();
void binary_search_m(char* n, char b, int i, int len);
void binary_search_f(char* n, char b, int i);

int main() {
	int botton = 0;
	do {
		printf("\n---------------------------------------------\n");
		printf("-----------20220315 데이터구조 과제----------\n");
		printf("---------------------------------------------\n");
		printf("-----------원하시는 버튼을 선택하세요--------\n");
		printf("---------------------------------------------\n");
		printf("--------1.문자열에서 각 조건이 모두 만족하는지 판별\n");
		printf("--------2.복소수의 전체 합 출력\n");
		printf("--------3.문자열의 길이 측정\n");
		printf("--------4.이진검색\n");
		printf("--------5.프로그램 종료\n");
		printf("--------6.화면 지우기\n");
		printf("---------------------------------------------\n");

		scanf_s("%d", &botton);

		switch (botton)
		{
			case 1:
			{
				checking_string();
				break;
			}
			case 2:
			{
				calculate_sum_of_complex_number();
				break;
			}
			case 3:
			{
				calculate_string_length(); 
				break;
			}
			case 4:
			{
				binary_search();
				break;
			}
			case 5:
			{
				printf("프로그램이 종료됩니다");
				return 0;
			}
			case 6:
			{
				system("cls");
				break;
			}
			default:
				break;
			}


	} while (botton != 5);

	return 0;
}

void checking_string() {
	char str[100] = { 0 };
	bool is_capital = false, is_lowercase = false, is_number = false, is_special_characters = false;
	int str_len = 0;
	printf("문자열을 입력하세요 대소문자 숫자 및 특수문자가 포함되어 10글자가 넘는지 확인해줍니다.\n");
	scanf_s("%s", &str, 100);
	int i = 0;

	for (i = 0; str[i] != NULL; i++) {
		if (str[i] >= 'a' && str[i] <= 'z')is_lowercase = true;
		else if (str[i] >= 'A' && str[i] <= 'Z')is_capital = true;
		else if (str[i] >= '0' && str[i] <= '9')is_number = true;
		else if (str[i] == '!' || str[i] == '?' || str[i] == '*' || str[i] == '#' || str[i] == '$')is_special_characters = true;
		else return 0;
	}

	str_len = i;

	if (is_capital == true && is_lowercase == true && is_number == true && is_special_characters == true && str_len >= 10)
		printf("모든 조건을 만족");
	else
		printf("조건을 만족하지 않습니다.");
}
void calculate_sum_of_complex_number() {
	Complex_number n[5] = {
		{5 , 3},
		{4 , 4},
		{-3 , 8},
		{15 , -4},
		{9 , 2}
	};
	int i = 0;
	int m = 0, k = 0;
	for (int h = 0; h < 5; h++) {
		printf("주어진 복소수는 %d+%di입니다.\n", n[h].imaginary_number, n[h].real_number);
	}
	sum(n, i, m, k);
}
void sum(Complex_number* n, int i, int m, int k) {
	if (i < 5) {
		m += (n + i)->real_number;
		k += (n + i)->imaginary_number;
		i++;
	}
	else {
		printf("복소수의 총합은 %d+%di입니다.", m, k);
		return 0;
	}
	return  sum(n, i, m, k);
}
void calculate_string_length() {
	char u_str[100] = { 0 };
	int i = 0;
	printf("문자열을 입력하세요 길이가 출력됩니다.\n");
	scanf_s("%s", &u_str, 100);
	printf("입력한 문자열의 길이는 %d입니다.", str_len(u_str, i));
}
int str_len(char* n, int i) {
	if (n[i] != NULL)i++;
	else return i;
	return str_len(n, i);
}
void binary_search() {
	char b_str = { 0 };
	char n_str[100] = { "123456789" };
	printf("숫자를 하나 입력하세요\n");
	scanf_s("%c", &b_str, 10);
	scanf_s("%c", &b_str, 10);
	int i = 0;
	int len = 0;
	printf("처음부터 찾기\n");
	binary_search_f(n_str, b_str, i);
	len = strlen(n_str) / 2;
	i = len;
	printf("중간부터 찾기\n");
	binary_search_m(n_str, b_str, i, len);
}
void binary_search_f(char* n, char b, int i) {
	int t = 0;
	if (n[i] == b) {
		printf("입력한 문자를 찾았습니다.위치는 %d번째입니다\n", i + 1);
		t = 1;
		return 0;
	}
	else if (n[i] == NULL) {
		printf("해당 문자를 찾지 못했습니다.\n");
		return 0;
	}
	else {
		printf("현재의 위치는%d입니다\n", i++ + 1);
	}
	return binary_search_f(n, b, i);
}

void binary_search_m(char* n, char b, int i, int len) {
	int t = 0;
	if (n[len] <= b) {

		if (n[i] == b) {
			printf("입력한 문자를 찾았습니다.위치는 %d번째입니다\n", i + 1);
			t = 1;
			return 0;
		}
		else if (n[i] == NULL) {
			printf("해당 문자를 찾지 못했습니다.\n");
			return 0;
		}
		else {
			printf("현재의 위치는%d입니다\n", i++ + 1);
			printf("오른쪽으로 한 칸 이동했습니다.\n");
		}
		return binary_search_m(n, b, i, len);
	}
	else {
		if (n[i] == b) {
			printf("입력한 문자를 찾았습니다.위치는 %d번째입니다\n", i + 1);
			t = 1;
			return 0;
		}
		else if (n[i] == NULL) {
			printf("해당 문자를 찾지 못했습니다.\n");
			return 0;
		}
		else {
			printf("현재의 위치는%d입니다\n", i-- + 1);
			printf("왼쪽으로 한 칸 이동했습니다.\n");
		}
		return binary_search_m(n, b, i, len);
	}
}
