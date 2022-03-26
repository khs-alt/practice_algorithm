#include <stdio.h>
#include <stdlib.h>



int main() {

    int number_of_card = 0, dealer_number = 0;
    int sum_of_card = 0;
    int tmp1 = 0;

    scanf_s("%d %d", &number_of_card, &dealer_number);


    int* card = (int*)malloc(sizeof(int) * number_of_card);


    for (int i = 0; i < number_of_card; ++i) scanf_s("%d", &card[i]);

    for (int i = 0; i < number_of_card; ++i) {
        for (int j = i+1; j < number_of_card; ++j) {
            for (int k = j+1; k < number_of_card; ++k) {
                sum_of_card = card[i] + card[j] + card[k];
                if (sum_of_card <= dealer_number && sum_of_card > tmp1) {
                    tmp1 = sum_of_card;
                }
            }
        }
    }

    printf("%d", tmp1);
}