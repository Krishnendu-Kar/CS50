#include <stdio.h>

int main(void){
    int a,b,c;
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);
    printf("Enter c: ");
    scanf("%d",&c);
    // printf("%d,%d,%d",a,b,c);
    
    if(a>b && a>c){
        printf("a is largest");
    }
    else if(b>a && b>c){
        printf("b is largest");
    }
    else{
        printf("C is largest");
    }

}