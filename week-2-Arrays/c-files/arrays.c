#include <stdio.h>

int main(void){
    int scores[3];

    for(int i=0; i<3;i++){
        printf("Enter score: ");
        scanf("%d", &scores[i]);
    }

    printf("Average: %f",((scores[0]+scores[1]+scores[2])/(float)3));
}