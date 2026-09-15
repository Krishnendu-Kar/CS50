#include <stdio.h>

int main(void){
    char name[50];

    printf("Enter your name here:");
    scanf("%s", &name);

    if(name){
        printf("Hello,%s",name);
    }
    else{
        printf("Hello,you");
    }
}