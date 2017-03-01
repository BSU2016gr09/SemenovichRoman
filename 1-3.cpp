/*Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.
  Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.*/

#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void inputArray(int * Array, int size);
void printArray(int * Array, int size);
void movePositives(int * Array, int size);
void sortArray(int * Array, int size);
void giveMemory(int * &Array, int size);
void deleteMemory (int * &Array);

int main()
{
    srand(time(NULL));
    int N;
    cout << "Введите размер массива: ";
    cin >> N;
    int * A;
    giveMemory(A, N);
    inputArray(A, N);
    cout << "\nВаш массив: ";
    printArray(A, N);
    movePositives(A, N);
    cout << "\nВаш массив после перемещения положительных элементов вправо: ";
    printArray(A, N);
    sortArray(A, N);
    cout << "\nВаш массив после сортировки: ";
    printArray(A, N);
    deleteMemory(A);
    A = nullptr;
    cout << "\n";
    return 0;
}

void giveMemory(int * &Array, int size){
    try{
        Array = new int [size];
    }
    catch(...){
        cout << "Память не выделилась :(\n";
        exit(0);
    }
}

void deleteMemory (int * &Array){
    delete [] Array;
}

void inputArray(int * Array, int size){
    for(int i = 0; i < size; i++){
        *(Array + i) = rand() % size - (size / 2) + 1;
    }
}

void printArray(int * Array, int size){
    for (int i = 0; i < size; i++){
        cout << *(Array + i) << " ";
    }
}

void movePositives(int * Array, int size){
    for (int i = size - 1; i >= 0; i--){
        if (*(Array + i) > 0){
            for (int j = i; j < size - 1; j++){
                swap(*(Array + j), *(Array + j + 1));
            }
            size--;
        }
    }
}

void sortArray(int * Array, int size){
    for (int i = 0; !(*(Array + i + 1) > 0) && i < size - 1; i++){
        for (int j = 0; !(*(Array + j + 1) > 0) && j < size - 1; j++){
            if (*(Array + j) < *(Array + j + 1)) swap(*(Array + j), *(Array + j + 1));
        }
    }
}

