#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int **generation() {
    int sudoku1[9][9] = {
        {4, 5, 7, 9, 3, 1, 6, 2, 8},
        {1, 2, 3, 7, 6, 8, 5, 4, 9},
        {9, 8, 6, 2, 5, 4, 3, 7, 1},
        {2, 7, 4, 6, 8, 9, 1, 5, 3},
        {8, 3, 1, 5, 7, 2, 4, 9, 6},
        {5, 6, 9, 4, 1, 3, 2, 8, 7},
        {6, 1, 2, 8, 9, 5, 7, 3, 4},
        {7, 9, 5, 3, 4, 6, 8, 1, 2},
        {3, 4, 8, 1, 2, 7, 9, 6, 5}
    };
    int sudoku2[9][9] = {
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

    int sudoku3[9][9] = {
        {8, 6, 1, 4, 9, 2, 7, 5, 3},
        {7, 9, 4, 5, 3, 6, 8, 1, 2},
        {5, 3, 2, 8, 7, 1, 4, 9, 6},
        {6, 1, 7, 9, 2, 8, 3, 4, 5},
        {9, 4, 8, 3, 6, 5, 1, 2, 7},
        {3, 2, 5, 1, 4, 7, 9, 6, 8},
        {1, 5, 6, 7, 8, 4, 2, 3, 9},
        {2, 8, 3, 6, 1, 9, 5, 7, 4},
        {4, 7, 9, 2, 5, 3, 6, 8, 1}
    };

    int sudoku4[9][9] = {
        {5, 1, 2, 6, 3, 7, 4, 9, 8},
        {8, 9, 4, 1, 2, 5, 7, 6, 3},
        {7, 3, 6, 8, 9, 4, 2, 1, 5},
        {1, 7, 3, 5, 8, 9, 6, 4, 2},
        {2, 6, 9, 4, 1, 3, 8, 5, 7},
        {4, 8, 5, 2, 7, 6, 1, 3, 9},
        {3, 4, 1, 7, 5, 8, 9, 2, 6},
        {6, 5, 8, 9, 4, 2, 3, 7, 1},
        {9, 2, 7, 3, 6, 1, 5, 8, 4}
    };

    int sudoku_provisoire[9][9] = {{},{},{},{},{},{},{},{},{}};

    srand(time(NULL));
    int aleatoire = rand() % 4+1;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            switch (aleatoire) {
                case 1:
                    sudoku_provisoire[i][j] = sudoku1[i][j];
                case 2:
                    sudoku_provisoire[i][j] = sudoku2[i][j];
                case 3:
                    sudoku_provisoire[i][j] = sudoku3[i][j];
                case 4:
                    sudoku_provisoire[i][j] = sudoku4[i][j];
            }
        }
    }



    srand(time(NULL));
    int val1 = rand() % 6+1;

    int sudoku[9][9] = {{},{},{},{},{},{},{},{},{}};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            switch (val1) {
                case 1:
                    sudoku[i][j] = sudoku_provisoire[i][j];
                case 2:
                    if (i==0 || i==1 || i==2) {
                        sudoku[i+3][j] = sudoku_provisoire[i][j];
                    }
                    else if (i==3 || i==4 || i==5) {
                        sudoku[i-3][j] = sudoku_provisoire[i][j];
                    }
                    else {
                        sudoku[i][j] = sudoku_provisoire[i][j];
                    }
                case 3:
                    if (i==0 || i==1 || i==2) {
                        sudoku[i+6][j] = sudoku_provisoire[i][j];
                    }
                    else if (i==6 || i==7 || i==8) {
                        sudoku[i-6][j] = sudoku_provisoire[i][j];
                    }
                    else {
                        sudoku[i][j] = sudoku_provisoire[i][j];
                    }
                case 4:
                    if (i==3 || i==4 || i==5) {
                        sudoku[i+3][j] = sudoku_provisoire[i][j];
                    }
                    else if (i==6 || i==7 || i==8) {
                        sudoku[i-3][j] = sudoku_provisoire[i][j];
                    }
                    else {
                        sudoku[i][j] = sudoku_provisoire[i][j];
                    }
                case 5:
                    if (i==0 || i==1 || i==2) {
                        sudoku[i+6][j] = sudoku_provisoire[i][j];
                    }
                    else if (i==3 || i==4 || i==5) {
                        sudoku[i-3][j] = sudoku_provisoire[i][j];
                    }
                    else {
                        sudoku[i-3][j] = sudoku_provisoire[i][j];
                    }
                case 6:
                    if (i==0 || i==1 || i==2) {
                        sudoku[i+3][j] = sudoku_provisoire[i][j];
                    }
                    else if (i==3 || i==4 || i==5) {
                        sudoku[i+3][j] = sudoku_provisoire[i][j];
                    }
                    else {
                        sudoku[i-6][j] = sudoku_provisoire[i][j];
                    }
            }
        }
    }

    srand(time(NULL));
    int val2 = rand() % 6+1;

    int sudoku_final[9][9] = {{},{},{},{},{},{},{},{},{}};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            switch (val2) {
                case 1:
                    sudoku_final[i][j] = sudoku1[i][j];
                case 2:
                    if (j==0 || j==1 || j==2) {
                        sudoku_final[i][j+3] = sudoku1[i][j];
                    }
                    else if (j==3 || j==4 || j==5) {
                        sudoku_final[i][j+3] = sudoku1[i][j];
                    }
                    else {
                        sudoku_final[i][j] = sudoku1[i][j];
                    }
                case 3:
                    if (j==0 || j==1 || j==2) {
                        sudoku_final[i][j+6] = sudoku1[i][j];
                    }
                    else if (j==6 || j==7 || j==8) {
                        sudoku_final[i][j+6] = sudoku1[i][j];
                    }
                    else {
                        sudoku_final[i][j] = sudoku1[i][j];
                    }
                case 4:
                    if (j==3 || j==4 || j==5) {
                        sudoku_final[i][j+3] = sudoku1[i][j];
                    }
                    else if (j==6 || j==7 || j==8) {
                        sudoku_final[i][j-3] = sudoku1[i][j];
                    }
                    else {
                        sudoku_final[i][j] = sudoku1[i][j];
                    }
                case 5:
                    if (j==0 || j==1 || j==2) {
                        sudoku_final[i][j+6] = sudoku1[i][j];
                    }
                    else if (j==3 || j==4 || j==5) {
                        sudoku_final[i][j-3] = sudoku1[i][j];
                    }
                    else {
                        sudoku_final[i][j-3] = sudoku1[i][j];
                    }
                case 6:
                    if (j==0 || j==1 || j==2) {
                        sudoku_final[i][j+3] = sudoku1[i][j];
                    }
                    else if (j==3 || j==4 || j==5) {
                        sudoku_final[i][j+3] = sudoku1[i][j];
                    }
                    else {
                        sudoku_final[i][j-6] = sudoku1[i][j];
                    }
            }

        }
    }

    int* p1 = malloc(9*sizeof(int));
    int* p2 = malloc(9*sizeof(int));
    int* p3 = malloc(9*sizeof(int));
    int* p4 = malloc(9*sizeof(int));
    int* p5 = malloc(9*sizeof(int));
    int* p6 = malloc(9*sizeof(int));
    int* p7 = malloc(9*sizeof(int));
    int* p8 = malloc(9*sizeof(int));
    int* p9 = malloc(9*sizeof(int));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            switch (i) {
                case 0:
                    p1[j] = sudoku_final[i][j];
                case 1:
                    p2[j] = sudoku_final[i][j];
                case 2:
                    p3[j] = sudoku_final[i][j];
                case 3:
                    p4[j] = sudoku_final[i][j];
                case 4:
                    p5[j] = sudoku_final[i][j];
                case 5:
                    p6[j] = sudoku_final[i][j];
                case 6:
                    p7[j] = sudoku_final[i][j];
                case 7:
                    p8[j] = sudoku_final[i][j];
                case 8:
                    p9[j] = sudoku_final[i][j];
            }
        }
    }

    int** sudoku_p = malloc(sizeof(void*) * 9);

    sudoku_p[0] = p1;
    sudoku_p[1] = p2;
    sudoku_p[2] = p3;
    sudoku_p[3] = p4;
    sudoku_p[4] = p5;
    sudoku_p[5] = p6;
    sudoku_p[6] = p7;
    sudoku_p[7] = p8;
    sudoku_p[8] = p9;

    return sudoku_p;
}

int **cache(int **matrice,int n) {
    
    int compteur = 0;
    while (compteur <= n) {

        srand(time(NULL));
        int a1 = rand() % 9;
        srand(time(NULL));
        int a2 = rand() % 9;

        if (matrice[a1][a2] != 0) {
            matrice[a1][a2] = 0;
            compteur++;
        }
    }
    return matrice;
}

int main(){
    int** a = generation();
    // for (int i = 0; i < 9; i++) {
    //     for (int j = 0; j < 9; j++) {
    //         printf("%d,",a[i][j]);
    //     }
    //     printf("\n");
    // }
    int** b = cache(a,27);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d,",b[i][j]);
        }
        printf("\n");
    }
}
