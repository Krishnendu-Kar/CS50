#include <stdio.h>

int global= 3;
int main(void){
    printf("%d\n",global);
    int scores[3];

    for(int i=0; i<3;i++){
        printf("Enter score: ");
        scanf("%d", &scores[i]);
    }

    printf("Average: %f",((scores[0]+scores[1]+scores[2])/(float)3));
}