#include <stdio.h>
#include <stdlib.h>

int input_function(void);
int position_available(int x, int y, int tab);
int affichage(int **tab);

int main() {
    int sudiku[9][9] = {
        {2, 8, 5, 6, 1, 3, 9, 4, 7},
        {4, 9, 3, 8, 7, 2, 5, 1, 6},
        {1, 6, 7, 4, 5, 9, 8, 2, 3},
        {3, 1, 9, 2, 6, 5, 4, 7, 8},
        {6, 4, 8, 7, 9, 1, 3, 5, 2},
        {5, 7, 2, 3, 8, 4, 1, 6, 9},
        {8, 3, 6, 1, 4, 7, 2, 9, 5},
        {7, 5, 1, 9, 2, 8, 6, 3, 4},
        {9, 2, 4, 5, 3, 6, 7, 8, 1}
    };
    printf("hello world");
    int x, y =  input_function();
    affichage(tab[9][9]);
    return 0;
}

int input_function(void) {
    int x;
    int y;
    printf("Give me 2 number\n");
    do {
        printf("Give me x: ");

        char *input = malloc(30);
        char *endPtr = malloc(30);

        fgets(input, 30, stdin);
        int value = strtof(input,&endPtr);

        if (input!=endPtr && value>0 && value<10) {
            x = value;
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
            y = value;
            break;
        }
    }while (1);
    return x, y;
}

int position_available(int x, int y, int tab) {
    if (x == 0 && y == 0) {
        return 1;
    }
    return 0;
}

int affichage(int **tab) {
    for (int i = 0; i < 8; i++) {
        printf("\n");
        for (int j = 0; j < 8; j++) {
            if (tab[i][j] == 0) {
                printf("%c", '.');
            } else {
                printf("%d ", tab[i][j]);
            }
            printf("------------------\n");
        }
    }


}