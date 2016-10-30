//выводит "перевернутый" массив
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void createArray(int a[], int N);
void printArray(int a[], int N);
void turnArray(int a[], int N);

int main(){
    srand(time(NULL));
    const int N = 10;
    //int Arr[N]; - http://stackoverflow.com/questions/5368531/why-cant-i-create-an-array-of-size-n
    // g++ - default compiler of QtCreator
    int a[N];
    createArray(a, N);
    cout<<"Массив: ";
    printArray(a, N);
    cout<<"Перевернутый массив: ";
    turnArray(a, N);
    printArray(a, N);
}

void createArray(int a[], int N){
    int i = 0;
    while (i < N){
        a[i] = rand() % (N - 1) + 1 ;
        i++;
    }
}

void printArray(int a[], int N){
    int i = 0;
    while (i < N){
        cout<<a[i]<<" ";
        i++;
    }
    cout<<"\n";
}

void turnArray(int a[], int N){
    int i = 0, j = N - 1; 
    while (i < N/2){
        swap(a[i], a[j]);// желаю увидеть код с одной переменной i. j здесь абсолютно не нужно!!!
        i++;
        j--;
    }
}
