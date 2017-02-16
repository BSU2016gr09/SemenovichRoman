//Транспонировать случайную квадратную матрицу (n,n)

#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int M = 3;
const int DOMAIN = 10;


void initArray(int matrix[][M]);
void printArray(int matrix[][M]);
void transposeMatrix(int matrix[][M]);

int main(){
    srand(time(NULL));
    int matrix[M][M];
    initArray(matrix);
    printArray(matrix);
    transposeMatrix(matrix);
    cout << "\n";
    printArray(matrix);
 }

void initArray(int matrix[][M]){
    for(int i = 0; i < M; i++)
        for (int j = 0; j < M; j++) matrix[i][j] = rand() % DOMAIN;
}

void printArray(int matrix[][M]){
    for(int i = 0; i < M; i++){
        for (int j = 0; j < M; j++) cout << setw(3) << matrix[i][j];
        cout << "\n";
    }
}

void transposeMatrix(int matrix[][M]){
    for(int i = 0; i < M; i++)
        for (int j = i; j < M; j++) swap(matrix[i][j],matrix[j][i]);
}
