//cоздание стека чисел и стека символов и демонтстрация их работоспособности
#include <QCoreApplication>
#include <iostream>

using namespace std;

void pushNum(double numbers, double stack[], int &top);
void popNum(int &top, int stackSize);
void fillStackOfNumbers(double stack[], double numbers[], int N, int &top);
void showStacksOfNumbersElements(double stack[], int &top, int stackSize);
void showStacksOfSymbolsElements(char stack[], int &top, int stackSize);
void fillStackOfSymbols(char stack[], char symbols[], int N, int &top);
void popSym(int &top, int stackSize);
void pushSym(char symbol, char stack[], int &top);


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
}


void pushNum(double numbers, double stack[], int &top){
    top--;
    if (top == -1){
        cout << "Нет места. Стек заполнен\n";
        top++;
        return;
    }
    stack[top] = numbers;
}

void popNum(int &top, int stackSize){
    top++;
    if (top == stackSize){
        cout << "Стек пуст\n";
        return;
    }
}

void fillStackOfNumbers(double stack[], double numbers[], int N, int &top){
    int i = 0;
    while (i < N){
        pushNum(numbers[i], stack, top);
        i++;
    }
}


void showStacksOfNumbersElements(double stack[], int &top, int stackSize){
    int i = top;
    cout << "Стек:\n";
    while (i < stackSize){
        cout << stack[top] << "\n";
        popNum(top, stackSize);
        i++;
    }
}


void pushSym(char symbol, char stack[], int &top){
    top--;
    if (top == -1){
        cout << "\nНет места. Стек заполнен\n";
        top++;
        return;
    }
    stack[top] = symbol;
}

void popSym(int &top, int stackSize){
    top++;
    if (top == stackSize){
        cout << "Стек пуст\n";
        return;
    }
}

void fillStackOfSymbols(char stack[], char symbols[], int N, int &top){
    int i = 0;
    while (i < N){
        pushSym(symbols[i], stack, top);
        i++;
    }
}


void showStacksOfSymbolsElements(char stack[], int &top, int stackSize){
    int i = top;
    cout << "Стек:\n";
    while (i < stackSize){
        cout << stack[top] << "\n";
        popSym(top, stackSize);
        i++;
    }
}
