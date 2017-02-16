//проверка числа, создание массива из случайных чисел, подсчет количества четных чисел в массиве
#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void checkNumber(int N);
void createArray(int array[], int N);
void printArray(int array[]);
void countPosEvNumbers(int array[]);



int main(){
    srand(time(NULL));
    int N;
    cout<<"Введите натуральное число (<=100): ";
    cin>>N;
    int array[10];
    checkNumber(N);
    createArray(array, N);
    printArray(array);
    countPosEvNumbers(array);
}

void checkNumber(int N){ //проверяет число на натуральность и количество цифр

    if (N > 100 || N <= 0){
        cout<<"Ошибка ввода!"<<"\n";
        abort();
        }
}

void createArray(int array[], int N){
    int min = -2*N, max = 3*N + 1;
    int i = 0;
    while (i < 10){
        array[i] = (rand()%max) + min;
        i++;
    }
}

void printArray(int array[]){
    int i = 0;
    while (i < 10){
        cout<<array[i]<<' ';
        i++;
    }

}

void countPosEvNumbers(int array[]){
    int i = 0, count = 0;
    while (i < 10){
        if (array[i] > 0 && array[i] % 2 == 0){
            count++;
        }
        i++;
    }
    cout<<"\n\nКоличество четных положительных чисел в массиве: "<< count << '\n';
}

