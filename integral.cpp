#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;

typedef double (*pf)(double);

double mySin(double);
double x2(double);
double reverseX(double);
double calcIntegral(int, int, double (*pf)(double), double);

int main()
{
    double a;
    double b;
    double epsilon;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите эпсилон: ";
    cin >> epsilon;
    int choise;
    cout << "От какой функции возьмем интеграл? 1. x^2; 2.sinx, 3.1/x: ";
    cin >> choise;
    switch (choise) {
    case 1:
        cout << calcIntegral(a, b, x2, epsilon) << "\n";
        break;
    case 2:
        cout << calcIntegral(a, b, mySin, epsilon) << "\n";
        break;
    case 3:
        cout << calcIntegral(a, b, reverseX, epsilon) << "\n";
        break;
    default:
        break;
    }

}

double mySin(double x){
    return sin(x);
}

double x2(double x){
    return x*x;
}

double reverseX(double x){
    return 1/x;
}

double calcIntegral(int a, int b, double (*pf)(double), double epsilon){
    int N = 20;
    double x;
    double l;
    double sum = 0, oldsum = 0;
    double rez;
    do{
        oldsum = sum;
        l = (double)(b - a) / N;
        x = a;
        while(x <= b){
            rez = pf(x);
            if (rez < 0) rez = -rez;
            x = x + l;
            sum = l * rez;
        }
        N += N/2;
    }
    while ((sum - oldsum) > epsilon);
    return sum;
}
