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
		printf("-----------20220315 �����ͱ��� ����----------\n");
		printf("---------------------------------------------\n");
		printf("-----------���Ͻô� ��ư�� �����ϼ���--------\n");
		printf("---------------------------------------------\n");
		printf("--------1.���ڿ����� �� ������ ��� �����ϴ��� �Ǻ�\n");
		printf("--------2.���Ҽ��� ��ü �� ���\n");
		printf("--------3.���ڿ��� ���� ����\n");
		printf("--------4.�����˻�\n");
		printf("--------5.���α׷� ����\n");
		printf("--------6.ȭ�� �����\n");
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
				printf("���α׷��� ����˴ϴ�");
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
	printf("���ڿ��� �Է��ϼ��� ��ҹ��� ���� �� Ư�����ڰ� ���ԵǾ� 10���ڰ� �Ѵ��� Ȯ�����ݴϴ�.\n");
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
		printf("��� ������ ����");
	else
		printf("������ �������� �ʽ��ϴ�.");
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
		printf("�־��� ���Ҽ��� %d+%di�Դϴ�.\n", n[h].imaginary_number, n[h].real_number);
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
		printf("���Ҽ��� ������ %d+%di�Դϴ�.", m, k);
		return 0;
	}
	return  sum(n, i, m, k);
}
void calculate_string_length() {
	char u_str[100] = { 0 };
	int i = 0;
	printf("���ڿ��� �Է��ϼ��� ���̰� ��µ˴ϴ�.\n");
	scanf_s("%s", &u_str, 100);
	printf("�Է��� ���ڿ��� ���̴� %d�Դϴ�.", str_len(u_str, i));
}
int str_len(char* n, int i) {
	if (n[i] != NULL)i++;
	else return i;
	return str_len(n, i);
}
void binary_search() {
	char b_str = { 0 };
	char n_str[100] = { "123456789" };
	printf("���ڸ� �ϳ� �Է��ϼ���\n");
	scanf_s("%c", &b_str, 10);
	scanf_s("%c", &b_str, 10);
	int i = 0;
	int len = 0;
	printf("ó������ ã��\n");
	binary_search_f(n_str, b_str, i);
	len = strlen(n_str) / 2;
	i = len;
	printf("�߰����� ã��\n");
	binary_search_m(n_str, b_str, i, len);
}
void binary_search_f(char* n, char b, int i) {
	int t = 0;
	if (n[i] == b) {
		printf("�Է��� ���ڸ� ã�ҽ��ϴ�.��ġ�� %d��°�Դϴ�\n", i + 1);
		t = 1;
		return 0;
	}
	else if (n[i] == NULL) {
		printf("�ش� ���ڸ� ã�� ���߽��ϴ�.\n");
		return 0;
	}
	else {
		printf("������ ��ġ��%d�Դϴ�\n", i++ + 1);
	}
	return binary_search_f(n, b, i);
}

void binary_search_m(char* n, char b, int i, int len) {
	int t = 0;
	if (n[len] <= b) {

		if (n[i] == b) {
			printf("�Է��� ���ڸ� ã�ҽ��ϴ�.��ġ�� %d��°�Դϴ�\n", i + 1);
			t = 1;
			return 0;
		}
		else if (n[i] == NULL) {
			printf("�ش� ���ڸ� ã�� ���߽��ϴ�.\n");
			return 0;
		}
		else {
			printf("������ ��ġ��%d�Դϴ�\n", i++ + 1);
			printf("���������� �� ĭ �̵��߽��ϴ�.\n");
		}
		return binary_search_m(n, b, i, len);
	}
	else {
		if (n[i] == b) {
			printf("�Է��� ���ڸ� ã�ҽ��ϴ�.��ġ�� %d��°�Դϴ�\n", i + 1);
			t = 1;
			return 0;
		}
		else if (n[i] == NULL) {
			printf("�ش� ���ڸ� ã�� ���߽��ϴ�.\n");
			return 0;
		}
		else {
			printf("������ ��ġ��%d�Դϴ�\n", i-- + 1);
			printf("�������� �� ĭ �̵��߽��ϴ�.\n");
		}
		return binary_search_m(n, b, i, len);
	}
}
