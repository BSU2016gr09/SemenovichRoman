//выводит "перевернутый" массив
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void createArray(int Arr[], int N);
void printArray(int Arr[], int N);
void turnArray(int Arr[], int N);

int main(){
    srand(time(NULL));
    const int N = 10;
    //int Arr[N]; - http://stackoverflow.com/questions/5368531/why-cant-i-create-an-array-of-size-n
    // g++ - default compiler of QtCreator
    int Arr[N];
    createArray(Arr, N);
    cout<<"Массив: ";
    printArray(Arr, N);
    cout<<"Перевернутый массив: ";
    turnArray(Arr, N);
    printArray(Arr, N);
}

void createArray(int Arr[], int N){
    int i = 0;
    while (i < N){
        Arr[i] = (rand() % (2*N + 1)) - N;
        i++;
    }
}

void printArray(int Arr[], int N){
    int i = 0;
    while (i < N){
        cout<<Arr[i]<<" ";
        i++;
    }
    cout<<"\n";
}

void turnArray(int Arr[], int N){
    int i = 0, j = N - 1;
    while (i < N/2){
        swap(Arr[i], Arr[j]);
        i++;
        j--;
    }
}
