//Написать программу, которая разбивает введенное предложение на слова

#include <QCoreApplication>
#include <iostream>
#include <clocale>

using namespace std;


void splitWords(char a[]);
int checkSymbols(char A);
void printLine (char a[]);
void deleteSection(char a[], int start, int lenght);

const long int MAX_LENGTH = 255;

int main()
{
    setlocale(LC_ALL, "Russian");
    char test1[MAX_LENGTH];
    cout << "Введите строку (по завершению введите '*'): ";
    cin.getline(test1, MAX_LENGTH, '*');

    cout << "\nВы ввели: ";
    printLine(test1);

    splitWords(test1);

    cout << "\nВаша строка после обработки: ";
    cout << "\n";
    printLine(test1);
    cout << "\n";
}


void printLine (char a[]){
    for (int i = 0; a[i]; i++){
        cout << a[i];
    }

}


void deleteSection(char a[], int start, int lenght){ //start - это индекс элемента в массиве
     int i = start;
     for (i; a[i]; i++){
         a[i] = a[i + lenght];
     }
     a[i] = 0;
}

int checkSymbols(char A){
    char sym[] = { ' ', ',', '.', 9}; //символы, которые могут разделять слова
    for (int j = 0; sym[j]; j++){
        if (A == sym[j]) return 1;
    }
    return 0;
}

void splitWords(char a[]){
    int flag = 0;
    for (int i = 0; a[i]; i++){
        if (!flag && checkSymbols(a[i])){
            a[i] = 10;
            flag = 1;
        }
        else{
            while (checkSymbols(a[i]) && a[i]){
            deleteSection(a, i, 1);
            }
                      flag = 0;
        }
    }
}
