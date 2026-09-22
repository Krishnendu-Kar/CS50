#include <stdio.h>

int input_height(void);
int print_height(int height);

int main(void){

    // #
    // ##
    // ###
    // ####
    // #####
    // ######

    // int i,c,h;

    // printf("Enter height: ");
    // scanf("%d",&h);

    // for(i=1;i<=h;i++){
    //     for(c=1;c<=i;c++){
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    
   
    // for(i=6;i>=1;i--){
    //     for(c=i;c>=1;c--){
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    // for(i=1;i<=6;i++){
    //     for(c=1;c<=i;c++){
    //         printf("#");
    //     }
    //     printf("\n");
    // }
    input_height();
}

int input_height(void){

    const int idx,co,height;

    printf("Enter height (f): ");
    scanf("%d",&height);

    print_height(height);
    return 0;
}

int print_height(int height){

    int i,c;

    for(i=1;i<=height;i++){
        for(c=1;c<=i;c++){
            printf("#");
        }
        printf("\n");
    }
}