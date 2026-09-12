#include <stdio.h>

int main(void){

    int i=3;
    while (i>0){
        printf("Meow\n");
        i--;
    }

    printf("Now start other loop:\n");

    for (int i=5;i>0;i--){
        printf("Melody\n");
    }
}