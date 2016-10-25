//проверка на натуральность, на кол-во цифр и вывод максимального числа с такими же цифрами
#include <QCoreApplication>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

void checkNumber(double N);
void getMaxNumber(double N);





int main(){
    double N;
    cout<<"2) Пользователь вводит с клавиатуры пятизначное натуральное число, которое сохраняется в переменную n, проверить корректность ввода, составить и вывести на экран число из цифр введённого числа n, так, чтобы выведенное число оказалось максимальным из возможных. Например, если пользователь ввёл число 22195, то программа должна вывести число 95221.\n";
    cout<<"\nPlease enter a natural five-digit number: ";
    cin>>N;

    checkNumber(N);
    getMaxNumber(N);
}


void checkNumber(double N){ //проверяет число на натуральность и количество цифр
    int counter = 0, copy = N;
    while (copy  != 0){
         copy /=10;
         counter+=1;
        }

    if (N < 1 || counter != 5 || floor(N) != N){
        cout<<"\nWrong input!\n\n";
        abort();

        }
}



void getMaxNumber(double N){
    int array[5];
    int i = 0;

    while (N  != 0){
         array[i] = int(N) % 10;
         N /=10;
         i++;
        }
    i = 0;

    for(int i = 0; i < 5 - 1; ++i)
        {
            for(int j = 0; j < 5 - 1; ++j)
            {
                if (array[j + 1] > array[j])
                {
                    swap(array[j],array[j+1]);
                }
            }
        }
    cout<<"\nThe biggest number is ";
    while (i < 5){
        cout<<array[i];

        i++;
    }
    cout<<'\n';
}
