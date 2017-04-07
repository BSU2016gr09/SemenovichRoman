#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;

typedef double (*pf)(double);

double mySin(double);
double x2(double);
double reverseX(double);
double reverse1PlusX2(double);
double reverseSin2(double);
double calcIntegral(int, int, pf, double);

int main()
{
    double a;
    double b;
    double epsilon;
    pf integral[] = {x2, mySin, reverseX, reverseSin2, reverse1PlusX2};
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите эпсилон: ";
    cin >> epsilon;
    int choise;
    cout << "От какой функции возьмем интеграл? 1. x^2; 2.sinx; 3.1/x; 4. 1/sin^2; 5. 1/(1 + x^2): ";
    cin >> choise;
    cout << "Интеграл: " << calcIntegral(a, b, *(integral[choise]), epsilon) << "\n";
}

double reverse1PlusX2(double x){
    return 1/(1 + x*x);
}

double reverseSin2(double x){
    return 1/sin(x)*sin(x);
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

double calcIntegral(int a, int b, double (*pf)(double), double epsilon){ //Масло маслянное. Ты же уже сделал typedef
    int N = 20;
    double x;
    double l;
    double sum = 0, oldsum = 0;
    do{
        oldsum = sum;
        sum = 0;
        l = (double)(b - a) / N;
        x = a;
        while(x < b){
            x = x + l;
            sum = sum + (l * fabs(pf(x)));
        }
        N += N*2;
    }
    while ((sum - oldsum) > epsilon);
    return sum;
}
