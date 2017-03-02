//Линейный конгруэнтный генератор псевдослучайных чисел

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
    static int previous = time(NULL) % 1000;
    int next;
    //int a = 4096, c = 150889, m = 714025; // (a)
    int a = 796, c = 5152, m = 64395; // (b)
    next = (a * previous + c) % m;
    previous = next;
    return next;
}

