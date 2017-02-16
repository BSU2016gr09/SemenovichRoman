//проверка на натуральность, на кол-во цифр и вывод максимального числа с такими же цифрами
#include <QCoreApplication>
#include <iostream>

using namespace std;

void checkNumber(int N);
void getMaxNumber(int N);

int main(){
    int N;
    cout<<"Введите пятизначное натуральное число: ";
    cin>>N;

    checkNumber(N);
    getMaxNumber(N);
}


void checkNumber(int N){ //проверяет число на натуральность и количество цифр
    if (N < 1 || N < 10000 || N > 99999){
        cout<<"\nОшибка ввода!\n\n";
        abort();
        }
}



void getMaxNumber(int N){
    int max = 0;
    while (N){
        if (max < (N % 10)) max = N % 10;
        N /=10;
    }
    cout << "\nМаксимальная цифра: " << max << '\n';
}
