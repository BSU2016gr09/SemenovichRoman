//сдвигает массив сначала вправо, затем -- влево
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void createArray(int Arr[], int N);
void printArray(int Arr[], int N);
void shiftArray(int Arr[], int N, int k);
void reverse(int Arr[], int N);
void shiftArray1(int Arr[], int N, int k);

int main(){
    srand(time(NULL));
    const int N = 10;
    int Arr[N], k;
    createArray(Arr, N);
    cout<<"Массив: ";
    printArray(Arr, N);
    cout<<"\nВведите сдвиг массива: ";
    cin>>k;
    shiftArray(Arr, N, k);
    cout<<"Сдвинутый вправо массив: ";
    printArray(Arr, N);
    cout<<"\nСдвинутый влево массив: ";
    shiftArray1(Arr, N, k);
    printArray(Arr, N);
    }

void createArray(int Arr[], int N){
    int i = 0;
    while (i < N){
        Arr[i] = (rand() % (2*N + 1)) - N;
        i++;
    }
}

void shiftArray(int Arr[], int N, int k){
    reverse(Arr, N - k);
    reverse(Arr + N - k, k);
    reverse(Arr, N);
}

void reverse(int Arr[], int N){
    if (N < 1) {
        return;
    }
    int i = 0, j = N - 1;
    while (i < j){
        swap(Arr[i], Arr[j]);
        i++;
        j--;
    }
}

void printArray(int Arr[], int N){
    int i = 0;
    while (i < N){
        cout<<Arr[i]<<" ";
        i++;
    }
}

void shiftArray1(int Arr[], int N, int k){
    reverse(Arr, k );
    reverse(Arr, N);
    reverse(Arr, N - k);
}
