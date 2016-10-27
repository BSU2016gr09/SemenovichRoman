//сдвигает массив сначала вправо, затем -- влево
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void createArray(int a[], int N);
void printArray(int a[], int N);
void shiftArray(int a[], int N, int k);
void reverse(int a[], int N);
void shiftArray1(int a[], int N, int k);

int main(){
    srand(time(NULL));
    const int N = 10;
    int a[N], k;
    createArray(a, N);
    cout<<"Массив: ";
    printArray(a, N);
    cout<<"\nВведите сдвиг массива: ";
    cin>>k;
    shiftArray(a, N, k);
    cout<<"Сдвинутый вправо массив: ";
    printArray(a, N);
    cout<<"\nСдвинутый влево массив: ";
    shiftArray1(a, N, k);
    printArray(a, N);
    }

void createArray(int a[], int N){
    int i = 0;
    while (i < N){
        a[i] = (rand() % (2*N + 1)) - N;
        i++;
    }
}

void shiftArray(int a[], int N, int k){
    reverse(a, N - k);
    reverse(a + N - k, k);
    reverse(a, N);
}

void reverse(int a[], int N){
    if (N < 1) {
        return;
    }
    int i = 0, j = N - 1;
    while (i < j){
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

void printArray(int a[], int N){
    int i = 0;
    while (i < N){
        cout<<a[i]<<" ";
        i++;
    }
}

void shiftArray1(int a[], int N, int k){
    reverse(a, k );
    reverse(a, N);
    reverse(a, N - k);
}
