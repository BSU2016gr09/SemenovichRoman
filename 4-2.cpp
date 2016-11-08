//Игра в "пьяницу"
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

void push(int queue[], int N, int &top, int element);
void pop(int &top, int tail, int queue[]);
void fillQueue(int queue[], int N);
void fillPack(int queue[], int N);
void dealCards(int first[], int second[], int pack[], int N, int &top1, int &top2);
void game1(int first [], int second[], int N, int &top1, int &top2, int pack[]);
void game2(int first [], int second[], int N, int &top1, int &top2, int pack[]);
void showCards(int card);

int main(){
    srand(time(NULL));
    int N = 36, top1 = N, top2 = N;
    int pack[N], first[N], second[N];
    game1(first, second, N, top1, top2, pack); //игра до одной победы
    //game2(first, second, N, top1, top2, pack); //игра на 5000 партий
    cout<<"\n";
}

void dealCards(int first[], int second[], int pack[], int N, int &top1, int &top2){
    int i = 0, j = 0;
    while (i < N/2){
        j = rand() % N;
        while (pack[j] == 0){
            j = rand() % N;
        }
        push(first, N, top1, pack[j]);
        j = rand() % N;
        while (pack[j] == 0){
            j = rand() % N;
        }
        push(second, N, top2, pack[j]);
        i++;
    }
}

void push(int queue[], int N, int &top, int element){
    int i = 0;
    while (i <= N - 1){
        queue[i] = queue[i + 1];
        i++;
    }
    top--;
    queue[N - 1] = element;

}

void pop(int &top, int queue[]){
    queue[top] = 0;
    top++;
}

void fillQueue(int queue[], int N){
    int i = 0;
    while (i < N){
        queue[i] = 0;
        i++;
    }
}

void fillPack(int queue[], int N){
    int i = 0;
    float  x = 6;
    while (i < N){
        queue[i] = floor(x);
        i++;
        x += 0.25;
    }
}

void game1(int first [], int second[], int N, int &top1, int &top2, int pack[]){
    int count = 0;
    fillQueue(pack, N);
    fillPack(pack, N);
    fillQueue(first, N);
    fillQueue(second, N);
    dealCards(first, second, pack, N, top1, top2);
    while (top1 != 0 && top2 != 0){
        ++count;
        cout<<"\n____________________________________"<< "\n\n\nКруг #"<<count<< "\n";
        cout<<"\nКарта первого игрока:"; showCards(first[top1]);
        cout<<"\nКарта второго игрока:"; showCards(second[top2]);
        if (first[top1] > second[top2]){
            if ((second[top2] == 6 && first[top1] == 14) || (second[top2] == 7 && first[top1] == 13)){
                cout<<"\n\nВторой забирает карту";
                push(second, N, top2, first[top1]);
                pop(top1, first);
                push(second, N, top2, second[top2]);
                pop(top2, second);
            }
            else {
                  cout<<"\n\nПервый забирает карту";
                  push(first, N, top1, second[top2]);
                  pop(top2, second);
                  push(first, N, top1, first[top1]);
                  pop(top1, first);
            }
        }
        else{
            if (first[top1] < second[top2]){
                    if ((first[top1] == 6 && second[top2] == 14) || (first[top1] == 7 && second[top2] == 13)){
                        cout<<"\n\nПервый забирает карту";
                        push(first, N, top1, second[top2]);
                        pop(top2, second);
                        push(first, N, top1, first[top1]);
                        pop(top1, first);
                    }
                    else {
                        cout<<"\n\nВторой забирает карту";
                        push(second, N, top2, first[top1]);
                        pop(top1, first);
                        push(second, N, top2, second[top2]);
                        pop(top2, second);
                    }
               }
            else{
                            cout<<"\n\nКарты равны";
                            push(first, N, top1, first[top1]);
                            pop(top1, first);
                            push(second, N, top2, second[top2]);
                            pop(top2, second);
        }
        }

}
   if (top1 < top2) cout<<"\nПобедил первый игрок!";
   else{ if(top2 < top1 ) cout<<"\nПобедил второй игрок!";
         else cout<<"\nНичья!";
        }
   cout<< "\nСыграно "<< count<< " кругов";


}


void game2(int first [], int second[], int N, int &top1, int &top2, int pack[]){
    int game = 0, count, MinNumber = 10000, MaxNumber = 0;
    while (game < 5000) {
        ++game;
        top1 = N; top2 = N;
        fillPack(pack, N);
        fillQueue(first, N);
        fillQueue(second, N);
        dealCards(first, second, pack, N, top1, top2);
        count = 0;
        while (top1 != 0 && top2 != 0){
            ++count;
            cout<<"\n____________________________________"<< "\n\n\nКруг #"<<count<< "\n";
            cout<<"\nКарта первого игрока:"; showCards(first[top1]);
            cout<<"\nКарта второго игрока:"; showCards(second[top2]);
            if (first[top1] > second[top2]){
                if ((second[top2] == 6 && first[top1] == 14) || (second[top2] == 7 && first[top1] == 13)){
                    cout<<"\n\nВторой забирает карту";
                    push(second, N, top2, first[top1]);
                    pop(top1, first);
                    push(second, N, top2, second[top2]);
                    pop(top2, second);
                }
                else {
                      cout<<"\n\nПервый забирает карту";
                      push(first, N, top1, second[top2]);
                      pop(top2, second);
                      push(first, N, top1, first[top1]);
                      pop(top1, first);
                }
            }
            else{
                if (first[top1] < second[top2]){
                        if ((first[top1] == 6 && second[top2] == 14) || (first[top1] == 7 && second[top2] == 13)){
                            cout<<"\n\nПервый забирает карту";
                            push(first, N, top1, second[top2]);
                            pop(top2, second);
                            push(first, N, top1, first[top1]);
                            pop(top1, first);
                        }
                        else {
                            cout<<"\n\nВторой забирает карту";
                            push(second, N, top2, first[top1]);
                            pop(top1, first);
                            push(second, N, top2, second[top2]);
                            pop(top2, second);
                        }
                   }
                else{
                                cout<<"\n\nКарты равны";
                                push(first, N, top1, first[top1]);
                                pop(top1, first);
                                push(second, N, top2, second[top2]);
                                pop(top2, second);
            }
            }
}
        if (MinNumber > count) MinNumber = count;
        if (MaxNumber < count) MaxNumber = count;


    }

   if (top1 < top2) cout<<"\nПобедил первый игрок!";
   else{ if(top2 < top1 ) cout<<"\nПобедил второй игрок!";
         else cout<<"\nНичья!";
        }
   cout<< "\nСыграно "<< game<< " партий";
   cout<< "\nМинимальное количество ходов: "<<MinNumber<<"\nМаксимальное: "<<MaxNumber<< "\nСреднее: " << (MinNumber+MaxNumber)/2;


}
void showCards(int card){
    cout<<"\n";
    switch(card){
        case 6:{
            cout<<"6";
            break;
        }
        case 7:{
            cout<<"7";
            break;
        }
        case 8:{
            cout<<"8";
            break;
        }
        case 9:{
            cout<<"9";
            break;
        }
        case 10:{
            cout<<"10";
            break;
        }
        case 11:{
            cout<<"Валет";
            break;
        }
        case 12:{
            cout<<"Дама";
            break;
        }
        case 13:{
            cout<<"Король";
            break;
        }
        case 14:{
            cout<<"Туз";
            break;
        }
    }
}
