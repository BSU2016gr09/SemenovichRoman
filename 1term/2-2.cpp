//сдвигает массив сначала вправо, затем -- влево на 1 элемент
#include <QCoreApplication>
#include <iostream>
#include <time.h>

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
    cout << "\n";
}

void createArray(int a[], int N){
    int i = 0;
    while (i < N) a[i++] = (rand() % (2*N + 1)) - N;
}

void printArray(int a[], int N){
    int i = 0;
    while (i < N) cout << a[i++] << "  ";

}

void shiftArrayToTheLeft(int a[], int N){
    int i = 0;
    int first = a[i];
    while (i < N - 1){
        a[i] = a[i + 1];
        i++;
    }
    a[i] = first;
}

void shiftArrayToTheRight(int a[], int N){
    int i = N - 1;
    int last = a[N - 1];
    while (i > 0){
        a[i] = a[i - 1];
        i--;
    }
    a[i] = last;
}

