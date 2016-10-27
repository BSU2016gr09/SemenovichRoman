//"перетусовка" с использованием доп.массива и просто меняя местами случайные элементы
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void createArray(int a[], int N);
void printArray(int a[], int N);
void mixArray1(int a[], int N);
void mixArray2(int a[], int N);

int main(){
    srand(time(NULL));
    const int N = 10;
    //int a[N]; - http://stackoverflow.com/questions/5368531/why-cant-i-create-an-aay-of-size-n
    // g++ - default compiler of QtCreator
    int a[N];
    createArray(a, N);
    cout<<"Массив: "; 
    printArray(a, N);
    cout<<"Перемешанный первым способом массив: ";
    mixArray1(a, N);
    printArray(a, N);
    cout<<"Перемешанный вторым способом массив: ";
    mixArray2(a, N);
    printArray(a, N);
}

void createArray(int a[], int N){
    int i = 0;
    while (i < N){
        a[i] = rand() % (N - 1) + 1 ;
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

void mixArray1(int a[], int N){
    int i = 0;
    while (i < N){
        swap(a[i], a[rand() % N]);
        i++;
    }
}

void mixArray2(int a[], int N){
    int b[N], j, i = 0;;
    while(i < N){
        b[i] = a[i];
        i++;
    }
    i = 0;
    while (i < N){
        j = rand() % N;
        while (b[j] == 0){
            j = rand() % N;
        }
        a[i] = b[j];
        b[j] = 0;
        i++;
    }


}
