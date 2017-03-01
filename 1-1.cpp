//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента

#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void inputArray(int * Array, int size);
void printArray(int * Array, int size);
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
        cout << "Память не выделилась :(";
        exit(0);
    }
}

void deleteMemory (int * &Array){
    delete [] Array;
}

void inputArray(int * Array, int size){
    for(int i = 0; i < size; i++){
        *(Array + i) = rand() % size + 1;
    }
}

void printArray(int * Array, int size){
    for (int i = 0; i < size; i++){
        cout << *(Array + i) << " ";
    }
}

void sortArray(int * Array, int size){
    int k;
    cout << "\nВведите индекс элемента, с которого начнется сортировка: ";
    cin >> k;
    for (int i = k; i < size - 1; i++){
        for (int j = k; j < size - 1; j++){
            if (*(Array + j) > *(Array + j + 1)) swap(*(Array + j), *(Array + j + 1));
        }
    }
}

