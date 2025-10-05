#include <stdio.h>

float average(int length, int array[]);

const int N;

int main(void){
    int scores[] = {13, 15, 17, 19};
    int N = 4;
    printf("The average is %.1f\n", average(N, scores));
}

float average(int length, int array[]){
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum = sum + array[i];
    }
    return sum / (float) length;
}
