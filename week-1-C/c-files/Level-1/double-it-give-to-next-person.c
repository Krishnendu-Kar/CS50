#include <stdio.h>


int main(void){
    long inr=1;

    while(true){
        char input;
        printf("Take %i for now or give to the next person? (if yes type y)",inr);
        scanf(" %c", &input);

        if (input== 'y')
            {
                inr *=2;
                printf("Okay, Giving %li to the next person\n",inr);
            }
        else{
            printf("Congrats, You have win %i\n",inr);
            break;
        }
    }
}
int main(void);