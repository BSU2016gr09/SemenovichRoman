//определение максимальной длины последовательности равных элементов
#include <QCoreApplication>
#include <iostream>
#include <ctime>

using namespace std;

void createArray(int a[], int N);
void printArray(int a[], int N);
void checkElements(int a[], int N);

int main(){
    srand(time(NULL));
    const int N = 5;
    int a[N];
    createArray(a, N);
    cout<<"Массив: ";
    printArray(a, N);
    checkElements(a, N);
    return 0;
}

void createArray(int a[], int N){
    int i = 0, MAX_RAND = 10;
    while (i < N){
        a[i] = rand() % (MAX_RAND + 1);
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


void checkElements(int a[], int N){
    int i = 0; int flag = 1, result = 0;
    while (i < N - 1){
        if (a[i] == a[i + 1]){
                flag++;
    }
        else{
                if (result < flag){
                result = flag;}
                flag = 1;
            }
        i++;
}
        cout<<"Максимальная длина последовательности равных элементов: "<<result<<"\n";
}
