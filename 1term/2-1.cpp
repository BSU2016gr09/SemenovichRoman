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
    const int N = 6;
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
    while (i < N) a[i++] = rand() % (N - 1) + 1 ;
}

void printArray(int a[], int N){
    int i = 0;
    while (i < N) cout << a[i++] <<"  ";
    cout<<"\n";
}

void turnArray(int a[], int N){
    int i = 0;
    while (i < N / 2){
        swap(a[i], a[N - 1 - i]);
        i++;
    }
}
