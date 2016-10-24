#include <QCoreApplication>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

void digitsSum(int N); //сумма цифр
void checkNumber(int N);  //проверяет число ТОЛЬКО на натуральность




int main(){
    cout<<"1) Пользователь вводит с клавиатуры натуральное число, проверить корректность ввода, вычислить и вывести на экран сумму цифр введённого пользователем числа.\n";
    int N;
    cout<<"\nPlease enter a natural number: ";
    cin>>N;

    checkNumber(N);
    digitsSum(N);

}

void checkNumber(int N){
    if (N < 1){
        cout<<"Wrong input!"<<"\n";
        abort();

        }
}

void digitsSum(int N){
    int sum = 0;
    while (N  != 0){
         sum += N % 10;
         N /=10;
        }
    cout<<"Digit's sum = "<<sum<<"\n";
}
