#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void inputArray(int * A, int N);
void printArray(int * A, int N);
void sortArray(int * A, int N);

int main()
{
    srand(time(NULL));
    int N;
    cout << "Введите размер массива: ";
    cin >> N;
    int * A = new int[N]; //Где выделение и контроль динамической памяти??? Почему выделение не в отдельной функции???
    inputArray(A, N);
    cout << "\nВаш массив: ";
    printArray(A, N);
    sortArray(A, N);
    cout << "\nВаш массив после сортировки: ";
    printArray(A, N);
    delete [] A;
    A = nullptr;
    cout << "\n";
    return 0;
}

void inputArray(int * A, int N){
    for(int i = 0; i < N; i++){
        A[i] = rand() % N + 1;
    }
}

void printArray(int * A, int N){
    for (int i = 0; i < N; i++){
        cout << *(A + i) << " ";
    }
}

void sortArray(int * A, int N){
    int k;
    cout << "\nВведите индекс элемента, с которого начнется сортировка: ";
    cin >> k;
    for (int i = k; i < N - 1; i++){
        for (int j = k; j < N - 1; j++){
            if (A[j] > A[j + 1]) swap(A[j],A[j + 1]);
        }
    }
}
