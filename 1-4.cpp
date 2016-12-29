//вывод элементов с нечетными и четными индексами

#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void printArray (float a[]);
void createArray(float a[]);
void printEvenIndex(float a[]);
void printOddIndex(float a[]);
const int N = 10;


int main(){
    srand(time(NULL));;
    float a[N];
    createArray(a);
    printArray(a);
    printOddIndex(a);
    printEvenIndex(a);
    cout << "\n";

}

void printArray (float a[]){
    int i = 0;
    while (i < N) cout << a[i++] << "  ";
    cout << '\n';
}

void createArray(float a[]){
    int i = 0;
    while (i < N){
        a[i] = (rand() % 1010 - 500) / 10.0;
        i++;
    }
}

void printEvenIndex(float a[]){
    int i = 0;
    cout << "\nНечетные индексы: ";
    while (i < N){
        cout << a[i] << ' ';
        i += 2;
    }
}

void printOddIndex(float a[]){
    int i = 1;
    cout << "\nЧетные индексы: ";
    while (i < N){
        cout << a[i]<<' ';
        i += 2;
    }
}
