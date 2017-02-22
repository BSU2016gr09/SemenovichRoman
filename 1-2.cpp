#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;

void inputPoints(char * Points, int * X, int * Y, int N);
void printPoints(char * Points, int * X, int * Y, int N);
void sortPoints(char * Points, int a, int b, int c, int * X, int * Y, int N);

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
    char * Points = new char [N];
    int * X = new int[N];
    int * Y = new int[N];
    inputPoints(Points, X, Y, N);
    sortPoints(Points, a, b, c, X, Y, N);
    printPoints(Points, X, Y, N);
    delete [] Y;
    delete [] X;
    Points = nullptr;
    X = nullptr;
    Y = nullptr;
    cout << "\n";
    return 0;
}

void inputPoints(char * Points, int *X, int *Y, int N){
    for (int i = 0; i < N; i++){
        Points[i] = 'A' + char(i);
    }
    for (int i = 0; i < N; i++){
        cout << "\nВведите координату X точки " << Points[i] << ": ";
        cin >> X[i];
        cout << "\nВведите координату Y точки " << Points[i] << ": ";
        cin >> Y[i];
    }
}

void printPoints(char * Points, int *X, int *Y, int N){
    for (int i = 0; i < N; i++){
        cout << Points[i] << "(" << X[i] << "; " << Y[i] << "), ";
    }
}

void sortPoints(char * Points, int a, int b, int c, int * X, int * Y, int N){
    int * Distance = new int[N];
    for (int i = 0; i < N; i++){
        Distance[i] = abs(a * X[i] + b * Y[i] + c) / sqrt(a * a + b * b);
    }
    for (int i = 0; i < N - 1; i++){
        for (int j = 0; j < N - 1; j++){
            if (Distance[j] > Distance[j + 1]){
                swap(Distance[j], Distance[j + 1]);
                swap(X[j], X[j + 1]);
                swap(Y[j], Y[j + 1]);
                swap(Points[j], Points[j + 1]);
            }
        }
    }
    delete [] Distance;
    Distance = nullptr;
}
