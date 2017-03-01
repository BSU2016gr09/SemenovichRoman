/*Даны точки плоскости своими координатами в виде двух одномерных массивов.
  Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0. */

#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;

void inputPoints(char * Points, int * X, int * Y, int size);
void printPoints(char * Points, int * X, int * Y, int size);
void sortPoints(char * Points, int a, int b, int c, int * X, int * Y, int size);
void giveMemory(int * &Array, int size);
void giveMemory(char * &Array, int size);
void deleteMemory (int * &Array);
void deleteMemory (char * &Array);

int main()
{
    int N;
    int a;
    int b;
    int c;
    cout << "Прямая ax + by + c = 0\nЗадайте коэффицент a у прямой: ";
    cin >> a;
    cout << "\nЗадайте коэффицент b у прямой: ";
    cin >> b;
    cout << "\nЗадайте коэффицент c у прямой: ";
    cin >> c;
    cout << "\n" << a << "x + " << b << "y + " << c << " = 0";
    cout << "\nВведите количество точек на плоскости: ";
    cin >> N;
    char * Points;
    int * X;
    int * Y;
    giveMemory(Points, N);
    giveMemory(X, N);
    giveMemory(Y, N);
    inputPoints(Points, X, Y, N);
    sortPoints(Points, a, b, c, X, Y, N);
    printPoints(Points, X, Y, N);
    deleteMemory(Points);
    deleteMemory(X);
    deleteMemory(Y);
    Points = nullptr;
    X = nullptr;
    Y = nullptr;
    cout << "\n";
    return 0;
}

void giveMemory(int * &Array, int size){
    try{
        Array = new int [size];
    }
    catch(...){
        cout << "Память не выделилась :(";
        exit(0);
    }
}

void deleteMemory (int * &Array){
    delete [] Array;
}

void giveMemory(char * &Array, int size){
    try{
        Array = new char [size];
    }
    catch(...){
        cout << "Память не выделилась :(";
        exit(0);
    }
}

void deleteMemory (char * &Array){
    delete [] Array;
}

void inputPoints(char * Points, int *X, int *Y, int size){
    for (int i = 0; i < size; i++){
       *(Points + i) = 'A' + char(i);
    }
    for (int i = 0; i < size; i++){
        cout << "\nВведите координату X точки " << *(Points + i) << ": ";
        cin >> *(X + i);
        cout << "\nВведите координату Y точки " << *(Points + i) << ": ";
        cin >> *(Y + i);
    }
}

void printPoints(char * Points, int *X, int *Y, int size){
    for (int i = 0; i < size; i++){
        cout << *(Points + i) << "(" << *(X + i) << "; " << *(Y + i) << "), ";
    }
}

void sortPoints(char * Points, int a, int b, int c, int * X, int * Y, int size){
    int * Distance;
    giveMemory(Distance, size);
    for (int i = 0; i < size; i++){
        *(Distance + i) = abs(a * *(X + i) + b * *(Y + i) + c) / sqrt(a * a + b * b);
    }
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1; j++){
            if (*(Distance + j) > *(Distance + j + 1)){
                swap(*(Distance + j), *(Distance + j + 1));
                swap(*(X + j), *(X + j + 1));
                swap(*(Y + j), *(Y + j + 1));
                swap(*(Points + j), *(Points + j + 1));
            }
        }
    }
    deleteMemory(Distance);
    Distance = nullptr;
}

