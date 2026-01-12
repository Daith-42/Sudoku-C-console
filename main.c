#include <stdio.h>
#include <stdlib.h>

int input_function(void);
int position_available(int x, int y, int tab);

int main() {
    input_function();
    return 0;
}

int input_function(void) {
    int X;
    int Y;
    printf("Give me 2 number\n");
    do {
        printf("Give me x: ");

        char *input = malloc(30);
        char *endPtr = malloc(30);

        fgets(input, 30, stdin);
        int value = strtof(input,&endPtr);

        if (input!=endPtr && value>0 && value<10) {
            X = value;
            break;
        }
    }while (1);

    do {
        printf("Give me y: ");

        char *input = malloc(30);
        char *endPtr = malloc(30);

        fgets(input, 30, stdin);
        int value = strtof(input,&endPtr);

        if (input!=endPtr && value>0 && value<10) {
            Y = value;
            break;
        }
    }while (1);
}

int position_available(int x, int y, int tab) {
    if (1 == 1) {
        return 1;
    }
    return 0;
}