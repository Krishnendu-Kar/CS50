#include <stdio.h>
#include <string.h>

int main(void){
    

    // char * word="HI ";  //read only
    char word[]="HI, I am Krishnendu Kar ";  //modify able

    printf("%s\n",word);

    //string length calculate
    int n =0;
    while(word[n] != '\0'){
        n++;
    }
    printf("Length of '%s' is: %d \n",word,n);
    printf("%d\n",strlen(word) );   //%zu, not %d: strlen returns size_t (unsigned), and %zu is its correct format specifier. %d often appears to work but is technically undefined behavior. If %zu prints oddly on your setup, cast instead: printf("%d\n", (int) strlen(word));.
    
    return 0;
}