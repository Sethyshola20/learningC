#include <stdio.h>

void draw(int num);
int main(void){
    char* s = "jj";
    int num = 100;
    draw(num);

}

void draw(int num){
    
    if(num <= 0){
        return;
    }

    draw(num - 1);

    for(int i = 0; i < num; i++){
        printf("#");
    }

    printf("\n");
}