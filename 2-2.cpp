//сдвигает массив сначала вправо, затем -- влево
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void createArray(int Arr[], int N);
void printArray(int Arr[], int N);
void changeArray1(int Arr[], int N);
void changeArray2(int Arr[], int N);

int main(){
    srand(time(NULL));
    const int N = 10;

    //int Arr[N]; - http://stackoverflow.com/questions/5368531/why-cant-i-create-an-array-of-size-n
    // g++ - default compiler of QtCreator
    int Arr[N];
    createArray(Arr, N);
    cout<<"Массив: ";
    printArray(Arr, N);
    changeArray1(Arr, N);
    cout<<"Сдвинутый вправо массив: ";
    printArray(Arr, N);
    changeArray2(Arr, N);
    cout<<"Сдвинутый влево массив: ";
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

void changeArray2(int Arr[], int N){
    int i = 0, tmp = Arr[0];
    while (i < N - 1){
        Arr[i] = Arr[i + 1];
        i++;
    }
    Arr[N-1] = tmp;
    i++;
    }


void changeArray1(int Arr[], int N){
    int i = N, tmp = Arr[N - 1];
    while (i > 0){
        Arr[i] = Arr[i - 1];
        i--;
    }
    Arr[0] = tmp;
}

