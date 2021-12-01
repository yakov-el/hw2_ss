
#include "my_mat.h"
#include <stdlib.h>
#include <stdio.h>

#define INF 1000000000
#define SIZE 10
int matrix[SIZE][SIZE];
int floyd[SIZE][SIZE];

int min(int, int);
void floyds(){

    // First Copy Matrix
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (i == j){floyd[i][j] = 0;}
            else if (matrix[i][j] == 0){floyd[i][j] = INF;}
            else{floyd[i][j] = matrix[i][j];}        
        }
    }
    int i, j, k;
    for (k = 0; k < SIZE; k++)
        for (i = 0; i < SIZE; i++)
            for (j = 0; j < SIZE; j++)
            {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }

    // for (int y = 0; y < SIZE; y++)
    // {
    //     for (int x = 0; x < SIZE; x++)
    //     {
    //         printf("%d ", floyd[y][x]);
    //     }
    // }
}
int min(int a, int b){
    if (a < b){return (a);}
    else{return (b);}
}

void setMatrix()
{
    int value = 0; // avoiding zevel
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            scanf("%d\n", &value);
            matrix[i][j] = value;
        }
    }
    // for (int i = 0; i < SIZE; i++)
    // {
    //     for (int j = 0; j < SIZE; j++)
    //     {
    //         printf("%d ", matrix[i][j]);
    //     }
    // }
    floyds();
}

int thereIsPath(int i, int j){

    if (floyd[i][j] != 0 && floyd[i][j] != INF){return 0; }
    else{return -1;}
}

void giveMeValue(int i, int j){
    
    int path = thereIsPath(i, j);
    if (path == 0){ printf("%d\n", floyd[i][j]);}
    else{printf("%d\n", path);}
}
