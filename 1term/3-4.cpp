//cоздание стека чисел и стека символов и демонтстрация их работоспособности
#include <QCoreApplication>
#include <iostream>

using namespace std;

void push(double numbers, double stack[], int &top);
void pop(int &top, int stackSize, double stack[]);//И очень неудачная реализация!!! Не ясно с каким именно стеком работаем? А если стеков несколько?????
void fillStackOfNumbers(double stack[], double numbers[], int N, int &top);
void showStacksOfNumbersElements(double stack[], int &top, int stackSize);//не понял зачем  int &top  ты ведь не меняешь там top
void showStacksOfSymbolsElements(char stack[], int &top, int stackSize);//не понял зачем  int &top  ты ведь не меняешь там top
void fillStackOfSymbols(char stack[], char symbols[], int N, int &top);
void pop(int &top, int stackSize, char stack);
void push(char symbol, char stack[], int &top);

int main(){
    int N = 6, stackSize = 5, top = stackSize;
    char symbols[N] = "qwerty", stackOfSymbols[stackSize];
    double numbers[N] = {1, 2, 3, 4, 5, 0};
    double stackOfNumbers[stackSize];
    fillStackOfNumbers(stackOfNumbers, numbers, N, top);
    cout << "Стек чисел:\n";
    showStacksOfNumbersElements(stackOfNumbers, top, stackSize);
    fillStackOfSymbols(stackOfSymbols, symbols, N, top);
    cout << "Стек символов:\n";
    showStacksOfSymbolsElements(stackOfSymbols, top, stackSize);
    cout << "\n";
}


void push(double numbers, double stack[], int &top){
    top--;
    if (top == -1){
        cout << "Нет места. Стек заполнен\n";
        top++;
        return;
    }
    stack[top] = numbers;
}

void pop(int &top, int stackSize, double stack[]){
    stack[top] = 0;
    top++;
    if (top == stackSize){
        cout << "Стек пуст\n";
        return;
    }
}

void fillStackOfNumbers(double stack[], double numbers[], int N, int &top){
    int i = 0;
    while (i < N){
        push(numbers[i], stack, top);
        i++;
    }
}


void showStacksOfNumbersElements(double stack[], int &top, int stackSize){
    int i = top;
    cout << "Стек:\n";
    while (i < stackSize){
        cout << stack[top] << "\n";
        pop(top, stackSize, stack);
        i++;
    }
}


void push(char symbol, char stack[], int &top){
    top--;
    if (top == -1){
        cout << "\nНет места. Стек заполнен\n";
        top++;
        return;
    }
    stack[top] = symbol;
}

void pop(int &top, int stackSize, char stack[]){
    stack[top] = '\0';
    top++;
    if (top == stackSize){
        cout << "Стек пуст\n";
        return;
    }
}

void fillStackOfSymbols(char stack[], char symbols[], int N, int &top){
    int i = 0;
    while (i < N){
        push(symbols[i], stack, top);
        i++;
    }
}


void showStacksOfSymbolsElements(char stack[], int &top, int stackSize){
    int i = top;
    cout << "Стек:\n";
    while (i < stackSize){
        cout << stack[top] << "\n";
        pop(top, stackSize, stack);
        i++;
    }
}
