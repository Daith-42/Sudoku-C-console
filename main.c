#include <stdio.h>
#include <stdlib.h>

int input_function(void);
int resolve(int x, int y, int tab[9][9]);
int affichage(int tab[9][9]);

int main() {
    int sudoku[9][9] = {
        {2, 8, 5, 6, 1, 3, 9, 4, 7},
        {4, 9, 3, 8, 7, 2, 5, 1, 6},
        {1, 6, 7, 4, 5, 9, 8, 2, 3},
        {3, 1, 9, 2, 6, 5, 4, 7, 8},
        {6, 4, 8, 0, 9, 1, 3, 5, 2},
        {5, 7, 2, 3, 8, 4, 1, 6, 9},
        {8, 3, 6, 1, 4, 7, 2, 9, 5},
        {7, 5, 1, 9, 2, 8, 6, 3, 4},
        {9, 2, 4, 5, 3, 6, 7, 8, 1}
    };
    int x, y, ninput =  input_function();
    resolve(x, y, sudoku);
    affichage(sudoku);
    return 0;
}

int input_function(void) {
    int x;
    int y;
    int ninput;
    printf("Give me 2 number\n");
    do {
        printf("Give me x: ");

        char *input1 = malloc(30);
        char *endPtr1 = malloc(30);

        fgets(input1, 30, stdin);
        int value = strtof(input1,&endPtr1);

        if (input1!=endPtr1 && value>0 && value<10) {
            x = value;
            free(input1);
            free(endPtr1);
            break;
        }
    }while (1);

    do {
        printf("Give me y: ");

        char *input2 = malloc(30);
        char *endPtr2 = malloc(30);

        fgets(input2, 30, stdin);
        int value = strtof(input2,&endPtr2);

        if (input2!=endPtr2 && value>0 && value<10) {
            y = value;
            free(input2);
            free(endPtr2);
            break;
        }
    }while (1);
    do {
        printf("Give me the number you want: ");

        char *input3 = malloc(30);
        char *endPtr3 = malloc(30);

        fgets(input3, 30, stdin);
        int value = strtof(input3,&endPtr3);

        if (input3!=endPtr3 && value>0 && value<10) {
            ninput = value;
            free(input3);
            free(endPtr3);
            break;
        }
    }while (1);

    return x, y, ninput;


}

int resolve(int x, int y, int tab[9][9]) {
    for (x = 0; x < sizeof(tab); x++) {
        for (y = 0; y < sizeof(tab); y++) {
            if (tab[x][y] == 0) {
                return 1;
            } else {
                return 0;
            }
            if (tab[x][y] != 0) {
                return 0;
                printf("%d \n", tab[x][y]);
                printf("End of the game");
            }
        }
    }
}

int affichage(int tab[9][9]) {
    for (int i = 0; i < 9; i++) {
        printf("\n");
        printf("+---+---+---+---+---+---+---+---+---+\n");
        for (int j = 0; j < 9; j++) {
            if (j == 0) {
                printf("| ");

            }
            if (tab[i][j] == 0) {
                printf(". | ");
            } else {
                printf("%d | ", tab[i][j]);
            }
        }
    }
    printf("\n+---+---+---+---+---+---+---+---+---+\n");
}