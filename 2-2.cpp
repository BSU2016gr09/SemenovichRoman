//XORShift

#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

int rand0m();
void getNumbers();

int main()
{
    getNumbers();
}

void getNumbers(){
    int N;
    cout << "Введите количество случайных чисел: ";
    cin >> N;
    for (int i = 0; i < N; i++){
        cout << "Случайное число " << i + 1 << ": " <<  rand0m() << "\n";
    }
}

int rand0m(){
    static int number = time(NULL) % 1000;
    int a = 13;
    int b = 15;
    int c = 5;
    number ^= number << a;
    number ^= number >> b;
    number ^= number << c;
    return number;
}

