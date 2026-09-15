#include <stdio.h>

int main(void){
    int i,num,sum=0;
    printf("Enter a number from sum to that: ");
    scanf("%d",num);
    for(i=1;i<=num;i++){
        sum = sum+i;
         printf("%d",sum);
    }
    printf("%d",sum);
}