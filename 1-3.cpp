#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void inputArray(int * A, int N);
void printArray(int * A, int N);
void movePositives(int * A, int N);
void sortArray(int * A, int N);

int main()
{
    srand(time(NULL));
    int N;
    cout << "Введите размер массива: ";
    cin >> N;
    int * A = new int[N];
    inputArray(A, N);
    cout << "\nВаш массив: ";
    printArray(A, N);
    movePositives(A, N);
    cout << "\nВаш массив после перемещения положительных элементов вправо: ";
    printArray(A, N);
    sortArray(A, N);
    cout << "\nВаш массив после сортировки: ";
    printArray(A, N);
    delete [] A;
    cout << "\n";
    return 0;
}

void inputArray(int * A, int N){
    for(int i = 0; i < N; i++){
        A[i] = rand() % N - (N / 2) + 1;
    }
}

void printArray(int * A, int N){
    for (int i = 0; i < N; i++){
        cout << *(A + i) << " ";
    }
}

void movePositives(int * A, int N){
    for (int i = N - 1; i >= 0; i--){
        if (*(A + i) > 0){
            for (int j = i; j < N - 1; j++){
                swap(*(A + j), *(A + j + 1));
            }
            N--;
        }
    }
}

void sortArray(int * A, int N){
    for (int i = 0; !(A[i + 1] > 0) && i < N - 1; i++){
        for (int j = 0; !(A[j + 1] > 0) && j < N - 1; j++){
            if (A[j] < A[j + 1]) swap(A[j],A[j + 1]);
        }
    }
}
