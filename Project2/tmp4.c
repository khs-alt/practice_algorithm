//#include <stdlib.h>
//#include <stdio.h>
//#include<string.h>
//
//void binary_search_f(char*n, char b, int i) {
//	int t = 0;
//	if (n[i] == b) {
//		printf("입력한 문자를 찾았습니다.위치는 %d번째입니다\n",i+1);
//		t = 1;
//		return 0;
//	}
//	else if (n[i] == NULL) {
//		printf("해당 문자를 찾지 못했습니다.\n");
//		return 0;
//	}
//	else {
//		printf("현재의 위치는%d입니다\n",i++ +1);
//	}
//	return binary_search_f(n, b, i);
//}
//
//void binary_search_m(char* n, char b, int i,int len) {
//	int t = 0;
//	if (n[len] <= b) {
//		
//		if (n[i] == b) {
//			printf("입력한 문자를 찾았습니다.위치는 %d번째입니다\n", i + 1);
//			t = 1;
//			return 0;
//		}
//		else if (n[i] == NULL) {
//			printf("해당 문자를 찾지 못했습니다.\n");
//			return 0;
//		}
//		else {
//			printf("현재의 위치는%d입니다\n", i++ + 1);
//			printf("오른쪽으로 한 칸 이동했습니다.\n");
//		}
//		return binary_search_m(n, b, i, len);
//	}
//	else {
//		if (n[i] == b) {
//			printf("입력한 문자를 찾았습니다.위치는 %d번째입니다\n", i + 1);
//			t = 1;
//			return 0;
//		}
//		else if (n[i] == NULL) {
//			printf("해당 문자를 찾지 못했습니다.\n");
//			return 0;
//		}
//		else {
//			printf("현재의 위치는%d입니다\n", i-- + 1);
//			printf("왼쪽으로 한 칸 이동했습니다.\n");
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
//	printf("처음부터 찾기\n");
//	binary_search_f(n_str,b_str,i);
//	len = strlen(n_str)/2;
//	i = len;
//	printf("중간부터 찾기\n");
//    binary_search_m(n_str, b_str, i, len);
//}