//Линейный конгруэнтный генератор псевдослучайных чисел

#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

int rand0m();

int main()
{
    int N;
    cout << "Введите количество случайных чисел: ";
    cin >> N;
    for (int i = 0; i < N; i++){
        cout << "Случайное число " << i + 1 << ": " <<  rand0m() << "\n";
    }
}

int rand0m(){
    static int previous = time(NULL) % 1000;
    int next;
    int a = 796;
    int c = 5152;
    int m = 64395;
    next = (a * previous + c) % m;
    previous = next;
    return next;
}

