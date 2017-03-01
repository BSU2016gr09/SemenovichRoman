/*Элементы массива А(N), значения которых – простые числа,
  расположить в порядке возрастания, не нарушая порядка следования других элементов.*/

#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void inputArray(int * Array, int size);
void printArray(int * Array, int size);
void sortArray(int * Array, int size);
int isPrime(int number);
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
        cout << "Память не выделилась :(\n";
        exit(0);
    }
}

void deleteMemory (int * &Array){
    delete [] Array;
}

void inputArray(int * Array, int size){
    for(int i = 0; i < size; i++){
        *(Array + i) = rand() % (size * 2) + 1;
    }
}

void printArray(int * Array, int size){
    for (int i = 0; i < size; i++){
        cout << *(Array + i) << " ";
    }
}

int isPrime(int number){
    int flag = 1;
    if (number == 1) return 1;
    if (number == 2) return 1;
    for(int i = 2; i < number / 2 + 1; i++){
        if(!(number % i)){
            flag = 0;
            break;
        }
    }
    return flag;
}


void sortArray(int * Array, int size){
    int * Prime;
    giveMemory(Prime, size);
    int pSize = 0;
    for (int i = 0; i < size; i++){
        if (isPrime( *(Array + i) )) {
            *(Prime + pSize) = i;
            pSize++;
        }
    }

    for (int i = 0; i < pSize - 1; i++){
        for (int j = 0; j < pSize - 1; j++){
            if (*(Array + *(Prime + j)) > *(Array + *(Prime + j + 1))) {
                swap(*(Array + *(Prime + j)),*(Array + *(Prime + j + 1)));
            }
        }
    }
    deleteMemory(Prime);
    Prime = nullptr;
}

