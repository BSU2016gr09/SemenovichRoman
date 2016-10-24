//вывод элементов с нечетными и четными индексами
#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void createArray(float array[]);
void printEvenIndex(float array[]);
void printOddIndex(float array[]);
const int N = 10;


int main(){
    cout<<"4) Объявить массив вещественных чисел размера N (число N объявить как константу). Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50. Вывести значения сначала элементов с нечетными коэффициентами (1-й, 3-й, 5-й,...) а затем - с четными\n";
    srand(time(NULL));;
    float array[N];
    createArray(array);
    printOddIndex(array);
    printEvenIndex(array);

}

void createArray(float array[]){
    int i = 0;
    while (i < N){
        array[i] = (rand() % 1001 - 500) / 10.0;
        i++;
    }
}

void printEvenIndex(float array[]){
    int i = 0, j = 1;
    cout<<"\nEven Index: ";
    while (i < 5){
        cout<<array[2*j - 1]<<' ';
        i++;
        j++;
    }
}

void printOddIndex(float array[]){
    int i = 0, j = -2 ;
    cout<<"\nOdd Index: ";
    while (i < 5){
        cout<<array[j + 2]<<' ';
        i++;
        j++;
    }
}
