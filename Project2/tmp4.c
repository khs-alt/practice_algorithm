//#include <stdlib.h>
//#include <stdio.h>
//#include<string.h>
//
//void binary_search_f(char*n, char b, int i) {
//	int t = 0;
//	if (n[i] == b) {
//		printf("�Է��� ���ڸ� ã�ҽ��ϴ�.��ġ�� %d��°�Դϴ�\n",i+1);
//		t = 1;
//		return 0;
//	}
//	else if (n[i] == NULL) {
//		printf("�ش� ���ڸ� ã�� ���߽��ϴ�.\n");
//		return 0;
//	}
//	else {
//		printf("������ ��ġ��%d�Դϴ�\n",i++ +1);
//	}
//	return binary_search_f(n, b, i);
//}
//
//void binary_search_m(char* n, char b, int i,int len) {
//	int t = 0;
//	if (n[len] <= b) {
//		
//		if (n[i] == b) {
//			printf("�Է��� ���ڸ� ã�ҽ��ϴ�.��ġ�� %d��°�Դϴ�\n", i + 1);
//			t = 1;
//			return 0;
//		}
//		else if (n[i] == NULL) {
//			printf("�ش� ���ڸ� ã�� ���߽��ϴ�.\n");
//			return 0;
//		}
//		else {
//			printf("������ ��ġ��%d�Դϴ�\n", i++ + 1);
//			printf("���������� �� ĭ �̵��߽��ϴ�.\n");
//		}
//		return binary_search_m(n, b, i, len);
//	}
//	else {
//		if (n[i] == b) {
//			printf("�Է��� ���ڸ� ã�ҽ��ϴ�.��ġ�� %d��°�Դϴ�\n", i + 1);
//			t = 1;
//			return 0;
//		}
//		else if (n[i] == NULL) {
//			printf("�ش� ���ڸ� ã�� ���߽��ϴ�.\n");
//			return 0;
//		}
//		else {
//			printf("������ ��ġ��%d�Դϴ�\n", i-- + 1);
//			printf("�������� �� ĭ �̵��߽��ϴ�.\n");
//		}
//		return binary_search_m(n, b, i, len);
//	}
//}
//
//int main() {
//	char b_str = { 0 };
//	char n_str[100] = { "123456789" };
//	scanf_s("%c", &b_str,10);
//	int i = 0;
//	int len = 0;
//	printf("ó������ ã��\n");
//	binary_search_f(n_str,b_str,i);
//	len = strlen(n_str)/2;
//	i = len;
//	printf("�߰����� ã��\n");
//    binary_search_m(n_str, b_str, i, len);
//}