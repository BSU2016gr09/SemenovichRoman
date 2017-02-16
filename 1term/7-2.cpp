// Найти в случайной матрице седловую точку если она там есть.
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
void findEverySaddlePoint(int matrix[][M]);
int checkSaddlePoint(int matrix[][M], int n, int m);

int main(){
    srand(time(NULL));
    int matrix[N][M];
    initArray(matrix);
    printArray(matrix);
    findEverySaddlePoint(matrix);
    cout << "\n";
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

void findEverySaddlePoint(int matrix[][M]){
    int min = DOMAIN, n, m, flag = 0;
    for (int i = 0; i < N; i++){ //находит минимальный элемент строки
       for (int j = 0; j < M; j++)
            if (matrix[i][j] < min){
                min = matrix[i][j];
                n = i; m = j; // n -- номер строки, m -- номер столбца
            }
       if (checkSaddlePoint(matrix, n, m)){ // проверяет максимален ли этот элемент в столбце
           flag = 1;
           cout << "\nСедловая точка (c координатами i = " << n + 1 << " и j = " << m + 1 << ") равна " << min << "\n";
       }
       min = DOMAIN;
    }
    if (!flag) cout << "\nСедловых точек нет";
}

int checkSaddlePoint(int matrix[][M], int n, int m){ // n -- номер строки, m -- номер столбца
    int max = 0, line;
    for (int i = 0; i < N; i++){
            if (matrix[i][m] > max){
                max = matrix[i][m];
                line = i;
            }
    }
    if (line == n) return 1;
    else return 0;
}

