//разделение массива на два других
#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void createArray(float array[], int N);
int indexB(float array[], int N);
int indexC(float array[], int N);
void printArray(float array[], int N);
void fillArrays(float array1[], float array2[], float array3[], int N);

int main(){
    cout<<"5) Объявить массив А вещественных чисел размера N (число N объявить как константу). Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50. Разделить массив А на два массива: положительные записать в массив В, отрицательные - в С.\n\n";
    srand(time(NULL));
    const int N = 10;
    float A[N];
    createArray(A, N);
    cout << "\nМассив А: ";
    printArray(A, N);
    int iB = indexB(A, N);
    float B[iB];
    int iC = indexC(A, N);
    float C[iC];
    fillArrays(A, B, C, N);
    cout<<"\nМассив B: ";
    printArray(B, iB);
    cout<<"\nМассив C: ";
    printArray(C, iC);
    cout << "\n";
}



void createArray(float array[], int N){
    int i = 0;
    while (i < N){
        array[i] = (rand() % 1010 - 500) / 10.0;
        i++;
    }
}

int indexB(float array[], int N){
    int i = 0, count = 0;
    while (i < N) if (array[i++] > 0) count++;
    return count;
}

int indexC(float array[], int N){
    int i = 0, count = 0;
    while (i < N) if (array[i++] < 0) count++;
    return count;
}

void printArray(float array[], int N){
    int i = 0;
    while (i < N) cout<<array[i++]<<"  ";

}

void fillArrays(float A[], float B[], float C[], int N){
    int i = 0, j = 0, k = 0;
    while (i < N){
        if (A[i] > 0) B[j++] = A[i];
        else if (A[i] < 0) C[k++] = A[i];
        i++;
       }
}
