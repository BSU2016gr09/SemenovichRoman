//сдвигает массив сначала вправо, затем -- влево на k элементов
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void createArray(int a[], int N);
void printArray(int a[], int N);
void shiftArrayToTheLeft(int a[], int N, int k);
void shiftArrayToTheRight(int a[], int N, int k);
void swapArrays(int a[], int b[], int N);

int main(){
    srand(time(NULL));
    const int N = 10;
    int a[N], k;
    createArray(a, N);

    cout<<"Массив: ";
    printArray(a, N);
    cout<<"\nВведите сдвиг массива: ";
    cin>>k;
    shiftArrayToTheRight(a, N, k);
    cout<<"\nСдвинутый вправо массив: ";
    printArray(a, N);
    shiftArrayToTheLeft(a, N, k);
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

void shiftArrayToTheLeft(int a[], int N, int k){
    int i = 0; int b[N];
    while (i < N){
        b[i] = a[(i + k) % N];
        i++;
    }
    swapArrays(a, b, N);
}

void shiftArrayToTheRight(int a[], int N, int k){
    int i = 0;
    int b[N];
    while (i < N){
        b[abs((i + k) % N)] = a[i];
        i++;
    }
    swapArrays(a, b, N);
}

void swapArrays(int a[], int b[], int N){
    int i = 0;
    while (i < N){
        a[i] = b[i];
        i++;
    }
}
