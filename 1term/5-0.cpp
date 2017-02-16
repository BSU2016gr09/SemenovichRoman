/* Заменить в строке, которую вводит пользователь все символы в словах на звездочки.
   Т.е. из строки "Мама мыла раму у бабушки" сделать строку "**** **** **** * *******" и распечатать ее в "столбик".
   Т.е. каждое полученное "слово" с новой строки.
*/

#include <QCoreApplication>
#include <iostream>
#include <clocale>
#include <QTextCodec>
#include <QDebug>
#include <QTextStream>

using namespace std;


void printLine (char a[]);
void changeSymbols(char a[]);
void splitWords(char a[]);
void deleteSection(char a[], int start, int lenght);
int checkSymbols(char A);

const long int MAX_LENGTH = 255;

int main()
{

    setlocale(LC_CTYPE, "Russian");
    char test[MAX_LENGTH];
    cout << "Введите строку (по завершению введите '*'): ";
    cin.getline(test, MAX_LENGTH, '*');
    splitWords(test);
    changeSymbols(test);
    cout << "\nОбработанная строка: \n";
    printLine(test);
    cout << "\n";
}

void printLine (char a[]){
    for (int i = 0; a[i]; i++){
        cout << a[i];
    }
}

void changeSymbols(char a[]){
    for (int i = 0; a[i]; i++){
        if (a[i] != 10)
            a[i] = '*';
    }
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

void deleteSection(char a[], int start, int lenght){ //start - это индекс элемента в массиве
     int i = start;
     for (i; a[i]; i++) a[i] = a[i + lenght];
     a[i] = 0;
}
