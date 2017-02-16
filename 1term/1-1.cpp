//вывод суммы цифр натурального числа
#include <QCoreApplication>
#include <iostream>

using namespace std;

void digitsSum(int N);

int main(){
    int N;
    cout<<"Введите натуральное число: ";
    cin>>N;
    digitsSum(N);
}


void digitsSum(int N){
    int sum = 0;
    while (N != 0){
         sum += int(N) % 10;
         N /=10;
        }
    cout<<"Сумма цифр = "<<sum<<"\n";
}
