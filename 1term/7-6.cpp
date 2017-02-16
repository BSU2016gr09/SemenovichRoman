//В матрице (n,m) удалить строки у которых максимальный элемент стоит первым, "подтянув" все остальные строки.

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
void deleteLine(int matrix[][M], int n);
void deleteLinesWithFirstMaxElement(int matrix[][M]);

int main(){
    srand(time(NULL));
    int matrix[N][M];
    initArray(matrix);
    printArray(matrix);
    deleteLinesWithFirstMaxElement(matrix);
    cout << "\n\n";
    printArray(matrix);
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


void deleteLine(int matrix[][M], int n){ // n -- номер строки
    if (n == N - 1){
        N--;
        return;
    }
    if (n > N - 1){
        cout << "\nОшибка, вы вышли за пределы матрицы";
        return;
    }
    for (int i = n; i < N - 1; i++)
        for (int j = 0; j < M; j++) matrix[i][j] = matrix[i + 1][j];
    N--;
}

void deleteLinesWithFirstMaxElement(int matrix[][M]){
    for (int i = 0; i < N; i++)
        for (int j = 1; j < M; j++){
            if (matrix[i][0] <= matrix[i][j]) break;
            if (j == M - 1) {
                deleteLine(matrix, i);
                i--;
            }
        }
}
