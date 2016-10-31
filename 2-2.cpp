//сдвигает массив сначала вправо, затем -- влево на 1 элемент
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void createArray(int a[], int N);
void printArray(int a[], int N);
void shiftArrayToTheLeft(int a[], int N);
void shiftArrayToTheRight(int a[], int N);

int main(){
    srand(time(NULL));
    const int N = 10;
    int a[N];
    createArray(a, N);
    cout<<"Массив: ";
    printArray(a, N);
    shiftArrayToTheRight(a, N);
    cout<<"\nСдвинутый вправо массив: ";
    printArray(a, N);
    shiftArrayToTheLeft(a, N);
    cout<<"\nСдвинутый влево массив: ";
    printArray(a, N);
}

void createArray(int a[], int N){
    int i = 0;
    while (i < N){
        a[i] = (rand() % (2*N + 1)) - N;
        i++;
    }
}

void printArray(int a[], int N){
    int i = 0;
    while (i < N){
        cout<<a[i]<<" ";
        i++;
    }
}

void shiftArrayToTheLeft(int a[], int N){
    int i = 0, first = a[0];
    while (i < N - 1){
        a[i] = a[i + 1];
        i++;
    }
    a[N - 1] = first;
}

void shiftArrayToTheRight(int a[], int N){
    int i = N - 1, last = a[i];
    while (i > 0){
        a[i] = a[i - 1];
        i--;
    }
    a[0] = last;
}
