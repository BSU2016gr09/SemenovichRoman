//игра в кости
#include <QCoreApplication>
#include <iostream>
#include <ctime>

using namespace std;

void Game(int Max);
void CheckSum(int sum1, int sum2);
void showCube(int value);

int main(){
    srand(time(NULL));
    const int Max = 50;
    Game(Max);
    return 0;
}

void Game(int Max){
    int hum_sum = 0, comp_sum = 0, MAX_RAND = 6;
    int cube1, cube2, index = 1;
    cout<<"Вы бросаете первым.";
    while (hum_sum < Max && comp_sum < Max){

        cout<<"\n\n\nКруг "<<index<<"\nНажмите клавишу Enter, чтобы сделать бросок.";
        cin.get();
        cube1 = 0; cube2 = 0;
        cube1 = rand() % MAX_RAND + 1;
        cube2 = rand() % MAX_RAND + 1;
        hum_sum = hum_sum + cube1 + cube2;
        cout<<"\nПервый кубик: ";
        showCube(cube1);
        cout<<"\nВторой кубик: ";
        showCube(cube2);
        cout<<"\n\nБросок ИИ.";
        cube1 = 0; cube2 = 0;
        cube1 = rand() % MAX_RAND + 1;
        cube2 = rand() % MAX_RAND + 1;
        comp_sum = comp_sum + cube1 + cube2;
        cout<<"\nПервый кубик: ";
        showCube(cube1);
        cout<<"\nВторой кубик: ";
        showCube(cube2);
        cout<<"\n\nВаша общая сумма: "<<hum_sum;
        cout<<"\nОбщая сумма ИИ: "<<comp_sum;
        index++;
    }
    cout<<"\n\n";
    CheckSum(hum_sum, comp_sum);
}

void CheckSum(int sum1, int sum2){
    if (sum1 > sum2){
        cout<<"Вы победили!";
    }
    else{
        if(sum1 == sum2){
        cout<<"Ничья.";
        }
        else {
            cout<<"Вы проиграли :(";
        }
}
    cout<<"\n";
}

void showCube(int value){
    switch(value){
        case 1:{
            cout<<"\n+---+"<<"\n|   |"<<"\n| O |"<<"\n|   |"<<"\n+---+";
            break;
            }
        case 2:{
            cout<<"\n+---+"<<"\n|O  |"<<"\n|   |"<<"\n|  O|"<<"\n+---+";
            break;
            }
        case 3:{
            cout<<"\n+---+"<<"\n|O  |"<<"\n| O |"<<"\n|  O|"<<"\n+---+";
            break;
            }
        case 4:{
            cout<<"\n+---+"<<"\n|O O|"<<"\n|   |"<<"\n|O O|"<<"\n+---+";
            break;
            }
        case 5:{
            cout<<"\n+---+"<<"\n|O O|"<<"\n| O |"<<"\n|O O|"<<"\n+---+";
            break;
            }
        case 6:{
            cout<<"\n+---+"<<"\n|O O|"<<"\n|O O|"<<"\n|O O|"<<"\n+---+";
            break;
            }
    }

}

