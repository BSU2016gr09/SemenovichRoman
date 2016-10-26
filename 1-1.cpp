//проверка числа на натуральность и вывод суммы цифр
#include <QCoreApplication>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

void digitsSum(double N);
void checkNumber(double N);




int main(){
    cout<<"1) Пользователь вводит с клавиатуры натуральное число, проверить корректность ввода, вычислить и вывести на экран сумму цифр введённого пользователем числа.\n";
    double N;//это натуральное????
    cout<<"\nPlease enter a natural number: ";
    cin>>N;

    checkNumber(N);
    digitsSum(N);

}

void checkNumber(double N){
    if (N < 1 || floor(N)!=N){
        cout<<"Wrong input!"<<"\n";
        abort();

        }
}

void digitsSum(double N){
    int sum = 0;
    while (N != 0){
         sum += int(N) % 10;
         N /=10;
        }
    cout<<"Digit's sum = "<<sum<<"\n";
}
