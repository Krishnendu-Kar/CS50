#include <stdio.h>

int main(void)
{
    char name[100];

    printf("What's your name? ");
    fgets(name, sizeof(name), stdin);

    printf("Hello, %s", name);

    return 0;
}