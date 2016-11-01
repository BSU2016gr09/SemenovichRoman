//проверка правильности растановки скобок в выражении c помощью стека
#include <QCoreApplication>
#include <iostream>

using namespace std;

void push(char test, char stack[], int size, int &top);
void pop(int &top);
void checkCorrectness(char test[], char stack[], int &top, int N, int size);


int main(){
    char test[]="(aa[b(c)ddd]e{ee})";
    int N = strlen(test), top = -1, stacksize = 30;
    char stack[stacksize];
    checkCorrectness(test, stack, top, N, stacksize);
}


void push(char test, char stack[], int size, int &top){
    top++;
    if (top == (size)){
        cout << "\nСтек переполнен";
        return;
    }
    stack[top] = test;
}

void pop(int &top){
    top--;
    if (top == -1){
        cout << "Стек пуст\n";
        return;
    }
}

void checkCorrectness(char test[], char stack[], int &top, int N, int size){
    int i = 0;
    while (i < N){
        if (test[i] == '(' || test[i] == '{' || test[i] == '['){
            push(test[i], stack, size, top);

        }
        else{
            if ((test[i] == ')' && stack[top] == '(') || (test[i] == '}' && stack[top] == '{') || (test[i] == ']' && stack[top] == '[')){
                pop(top);
            }
            else {
                if (test[i] == ')' || test[i] == '}' || test[i] == ']'){
                    cout << "Неправильный ввод\n";
                    return;
                }
            }
        }
        i++;
    }
    if (top == -1){
        cout << "Всё верно\n";
        return;
    }
}
