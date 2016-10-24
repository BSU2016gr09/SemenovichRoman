//проверка числа, создание массива из случайных чисел, подсчет количества четных чисел в массиве   
#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

void checkNumber(int N);
void createArray(int array[], int N);
void printArray(int array[]);
void showPosEvNumbers(int array[]);



int main(){
    srand(time(NULL));
    int N;
    cout<<"3) Пользователь вводит с клавиатуры натуральное число не большее 100, которое сохраняется в переменную n, проверить корректность ввода, создать массив из 10 случайных целых чисел из отрезка [-2n;n], вывести массив на экран в строку, подсчитать и и вывести на экран количество положительных чётных чисел в массиве.\n";
    cout<<"\nPlease enter a natural number (<=100): ";
    cin>>N;
    int array[10];
    checkNumber(N);
    createArray(array, N);
    printArray(array);
    showPosEvNumbers(array);
}

void checkNumber(int N){ //проверяет число на натуральность и количество цифр

    if (N >= 100 || N <= 0){
        cout<<"Wrong input!"<<"\n";
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

void showPosEvNumbers(int array[]){
    int i = 0, count = 0;
    while (i < 10){
        if (array[i] > 0 && array[i] % 2 == 0){
            count++;
        }
        i++;
    }
    cout<<"\n\nThe number of positive even numbers = "<<count<<'\n';
}

