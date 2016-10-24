//разделение массива на два других
#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

const int N = 10;
void createArray(int array[]);
int indexB(int array[]);
int indexC(int array[]);
void printArray(int array[], int n);
void fillArrays(int array1[], int array2[], int array3[], int N);

int main(){
    cout<<"5) Объявить массив А вещественных чисел размера N (число N объявить как константу). Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50. Разделить массив А на два массива: положительные записать в массив В, отрицательные - в С.\n\n";
    srand(time(NULL));
    int A[N];
    createArray(A);
    int n1 = indexB(A);
    int B[n1];
    int n2 = indexC(A);
    int C[n2];
    fillArrays(A, B, C, N);
    cout<<"Massive B: ";
    printArray(B, n1);
    cout<<"\nMassive C: ";
    printArray(C, n2);
}



void createArray(int array[]){
    int i = 0;
    while (i < N){
        array[i] = (rand() % 101 - 50);
        i++;
    }
}

int indexB(int array[]){
    int i = 0, count = 0;
    while (i < N){
        if (array[i] > 0){
            count++;
        }
        i++;
    }
    return count;
}

int indexC(int array[]){
    int i = 0, count = 0;
    while (i < N){
        if (array[i] < 0){
            count++;
        }
        i++;
    }
    return count;
}

void printArray(int array[], int n){
    int i = 0;
    while (i < n){
        cout<<array[i]<<" ";

        i++;
    }

}

void fillArrays(int array1[], int array2[], int array3[], int N){
    int i = 0, j = 0, k = 0;
    while (i < N){
        if (array1[i] > 0){
            array2[j] = array1[i];
            j++;
        }
        else if (array1[i] < 0){
            array3[k] = array1[i];
            k++;
        }
        i++;
}
}
