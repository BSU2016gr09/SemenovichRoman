//выводит "перевернутый" массив
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void createArray(int Arr[], int N);
void printArray(int Arr[], int N);
void turnArray(int Arr[], int N);

int main(){
    srand(time(NULL));
    int N;
    cout<<"Enter the size of the array: ";//договариваились, что комментраии или на русском цi на беларускай лацiнiце!!!
    cin>>N;
    int Arr[N];// интересно, что у тебя за транслятор, который позволяет так выделять память НЕИЗВЕСТНОГО размера (N во время трансляции НЕИЗВЕСТНО!!!!!!!
    createArray(Arr, N);
    cout<<"The array: ";
    printArray(Arr, N);
    cout<<"The inverse array: ";
    turnArray(Arr, N);
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

void turnArray(int Arr[], int N){
    int i = 0, j = N - 1;
    while (i < N/2){
        swap(Arr[i], Arr[j]);
        i++;
        j--;
    }
}
