//В матрице (n,m) найти те строки и вывести их номера, элементы которых образуют возрастающую последовательность.
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
void checkLines(int matrix[][M]);

int main(){
    srand(time(NULL));
    int matrix[N][M];
    initArray(matrix);
    printArray(matrix);
    //checkLines(matrix);
    cout << "\n\n";
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

void checkLines(int matrix[][M]){
    int flag = 0;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < M - 1; j++)
            if (matrix[i][j] > matrix[i][j + 1]) flag = 1;
        if (!flag) cout << "\nНомер строки с возрастающей последовательностью: " << i + 1;
        flag = 0;
    }
}
