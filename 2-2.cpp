//сдвигает массив сначала вправо, затем -- влево
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void createArray(int a[], int N);
void printArray(int a[], int N);
void changeArray1(int a[], int N);
void changeArray2(int a[], int N);

int main(){
    srand(time(NULL));
    const int N = 10;

    //int Arr[N]; - http://stackoverflow.com/questions/5368531/why-cant-i-create-an-array-of-size-n
    // g++ - default compiler of QtCreator
    int a[N];
    createArray(a, N);
    cout<<"Массив: ";
    printArray(a, N);
    changeArray1(a, N);
    cout<<"Сдвинутый вправо массив: ";
    printArray(a, N);
    changeArray2(a, N);
    cout<<"Сдвинутый влево массив: ";
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
    cout<<"\n";
}

void changeArray2(int a[], int N){
    int i = 0, tmp = a[0];
    while (i < N - 1){
        a[i] = a[i + 1];
        i++;
    }
    a[N-1] = tmp;
    i++;
    }


void changeArray1(int a[], int N){
    int i = N, tmp = a[N - 1];
    while (i > 0){
        a[i] = a[i - 1];
        i--;
    }
    a[0] = tmp;
}

