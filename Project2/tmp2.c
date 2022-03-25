//#include <stdio.h>
//
//typedef struct Complex_number
//{
//	int a;
//	int b;
//}Complex_number;
//
//void sum(Complex_number *n,int i,int m, int k) {
//	if (i < 5) {
//		m += (n + i)->a;
//		k += (n + i)->b;
//		i++;
//	}
//	else { 
//		printf("두 복소수의 합은 %d+%di입니다.", m, k);
//		return 0;
//	}
//	return  sum(n, i, m, k);
//}
//
//int main() {
//	Complex_number n[5] = {
//		{5 , 3},
//		{4 , 4},
//		{-3 , 8},
//		{15 , -4},
//		{9 , 2}
//	};
//	int i = 0;
//	int m = 0, k = 0;
//	sum(n,i,m,k);
//}
//
