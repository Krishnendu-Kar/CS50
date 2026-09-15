#include <stdio.h>

int main(void){
    int num;
    printf("Enter a number to check odd or even: ");
    scanf("%d",&num);
    if((num%2)==0){
        printf("%d is even",num);
    }
    if((num%2)!=0){
        printf("%d is odd",num);
    }
}