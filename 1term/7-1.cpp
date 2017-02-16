//Найти в случайной матрице минимум в каждом столбце.
#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int M = 3;
int N = 3;
const int DOMAIN = 10;


void initArray(int matrix[][M]);
void printArray(int matrix[][M]);
void findEveryColumnsMinimum(int matrix[][M]);
int main(){
    srand(time(NULL));
    int matrix[N][M];
    initArray(matrix);
    printArray(matrix);
    findEveryColumnsMinimum(matrix);
}

void initArray(int matrix[][M]){
    for(int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) matrix[i][j] = rand() % DOMAIN;
}

void printArray(int matrix[][M]){
    for(int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) cout << setw(3) << matrix[i][j];
        cout << "\n";
    }
}

void findEveryColumnsMinimum(int matrix[][M]){
    int min = DOMAIN;
    for (int i = 0; i < M; i++){
       for (int j = 0; j < N; j++)
            if (matrix[j][i] < min) min = matrix[j][i];
       cout << "Минимум столбца " << i + 1 << " равен " << min << "\n";
       min = DOMAIN;
    }
}
