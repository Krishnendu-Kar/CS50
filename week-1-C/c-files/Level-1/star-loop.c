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


// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     for (int i = -2; i <= 2; i++) {
//         int s = abs(i);
//         for (int j = 0; j < s; j++) putchar(' ');
//         for (int j = 0; j < 5 - 2 * s; j++) putchar('*');
//         putchar('\n');
//     }
//     return 0;
// }


#include <stdio.h>

int main() {
    int size = 5;  
    int row, space, star;

    for (row = 1; row <= size; row++) {
        for (space = 1; space <= size - row; space++) {
            printf(" ");
        }
        for (star = 1; star <= 2 * row - 1; star++) {
            printf("*");
        }
        printf("\n");  
    }
    for (row = size - 1; row >= 1; row--) {
        for (space = 1; space <= size - row; space++) {
            printf(" ");
        }
        for (star = 1; star <= 2 * row - 1; star++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}