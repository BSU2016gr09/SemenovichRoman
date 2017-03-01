#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void inputArray(int * A, int N);
void printArray(int * A, int N);
void sortArray(int * A, int N);
int isPrime(int number);

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

void sortArray(int * A, int N){
    int * Prime = new int[N];
    int z = 0;
    for (int i = 0; i < N; i++){
        if(isPrime(A[i])){
            Prime[z] = i;
            z++;
        }
    }
    for (int i = 0; i < z - 1; i++){
        for (int j = 0; j < z - 1; j++){
            if (A[Prime[j]] > A[Prime[j + 1]]) {
                swap(A[Prime[j]],A[Prime[j + 1]]);
            }
        }
    }
    delete [] Prime;
    Prime = nullptr;
}
