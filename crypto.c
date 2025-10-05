#include <stdio.h>

void crypto(int argc, char arg[]);

int main(int argc, char* argv[]){
    for(int i = 1; i < argc; i++){
        crypto(argc, argv[i]);
    }
    return 0;
}

void crypto(int argc, char arg[]){
    for(int i = 0; i < argc; i++){
        printf("%p\n", &arg[i]);
    }
}