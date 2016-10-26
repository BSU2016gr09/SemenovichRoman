//разделение массива на два других
#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

const int N = 10;//Ой как плохо.... Глобальная переменная!!!!
void createArray(float array[]);
int indexB(float array[]);
int indexC(float array[]);
void printArray(float array[], int n);
void fillArrays(float array1[], float array2[], float array3[], int N);

int main(){
    cout<<"5) Объявить массив А вещественных чисел размера N (число N объявить как константу). Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50. Разделить массив А на два массива: положительные записать в массив В, отрицательные - в С.\n\n";
    srand(time(NULL));
    float A[N];
    createArray(A);
    int n1 = indexB(A);
    float B[n1];
    int n2 = indexC(A);
    float C[n2];
    fillArrays(A, B, C, N);//Зачем передавать тогда N если она глобальная
    cout<<"Massive B: ";
    printArray(B, n1);
    cout<<"\nMassive C: ";
    printArray(C, n2);
}



void createArray(float array[]){
    int i = 0;
    while (i < N){
        array[i] = (rand() % 1010 - 500) / 10.0;
        i++;
    }
}

int indexB(float array[]){
    int i = 0, count = 0;
    while (i < N){
        if (array[i] > 0){
            count++;
        }
        i++;
    }
    return count;
}

int indexC(float array[]){
    int i = 0, count = 0;
    while (i < N){
        if (array[i] < 0){
            count++;
        }
        i++;
    }
    return count;
}

void printArray(float array[], int n){
    int i = 0;
    while (i < n){
        cout<<array[i]<<" ";

        i++;
    }

}

void fillArrays(float array1[], float array2[], float array3[], int N){
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
