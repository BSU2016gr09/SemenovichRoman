/*В дополнение к уже сделанным на практике функциям реализовать аналог функций стандартной библиотеки, находящиеся в заголовочном файле.
Наиболее часто используемые функции. */

#include <QCoreApplication>
#include <iostream>
#include <clocale>

using namespace std;

int strlen(char words[]);
void strcpy(char str1[], char str2[]);
void  strNcpy(char str1[], char str2[], int size);
int strchr(char str[], char sym);
int strRchr(char str[], char sym);
void strcat(char str1[], char str2[]);
void strNcat(char str1[], char str2[], int size);
int deleteSymbols(char a[], int start, int end); //удаляет в строки символы от start до end
int deleteRepeat (char a[]); //удаляет все повторяющиеся символы
int deleteRepeatSymbol (char a[], char sym); //удаляет повторяющийся элемент
int deleteSymbol (char a[], char sym); //удаляет символ
int deleteFirstSymbols (char a[]); //разбить строку на слова
void deleteSection(char a[], int i, int lenght);
int deleteBesidesRepeat (char a[]);
void printLine (char a[]);

const long int MAX_LENGTH = 255;

int main()
{
    setlocale(LC_ALL, "Russian");
    char test1[MAX_LENGTH], test2[]= {"qwerty"}; int N, start, end; char sym;
    cout << "Введите строку (по завершению введите '*'): ";
    cin.getline(test1, MAX_LENGTH, '*');

    cout << "\nВы ввели: ";
    printLine(test1);



    //cout << "\nВведите номер элемента, с которого начнется удаление: ";
    //cin >> start;
    //cout << "\nВедите номер элемента, на котором закончится удаление: ";
    //cin >> end;
    //if (!deleteSymbols(test1, start, end)) cout << "Некорректно введены номера.\n";
    //cout << "\nВведите символ, повторения которого хотите удалить: ";
    //cin >> sym;
    //if (!deleteRepeatSymbol(test, sym)) cout << "\nТакого символа нет в строке.\n";
    //cout << "\nВведите символ, который хотите удалить: ";
    //cin >> sym;
    //if (!deleteSymbol(test1, sym)) cout << "\nТакого символа нет в строке.\n";
    //if (!deleteRepeat(test1)) cout << "\nВ строке нет повторяющихся символов";
    //if (!deleteBesidesRepeat (test1)) cout << "\nВ строке рядом стоящие символы не повторяются";
    //strcpy(test1, test2);
    //cout << "\nВведите количество символов, которое должно быть скопировано: ";
    //cin >> N;
    //strNcpy(test1, test2, N);
    //strcat(test1, test2);
    //cout << "\nВведите количество символов, которое должно быть присоединено: ";
    //cin >> N;
    //strNcat(test1, test2, N);
    //cout << "\nВведите символ, первое вхождение которого нужно найти: ";
    //cin >> sym;
    //cout << "\nСимвол '" << sym << "' впервые встречается на " << strchr(test1, sym)  << " позиции\n";
    //cout << "\nВведите символ, последнее вхождение которого нужно найти: ";
    //cin >> sym;
    //cout << "\nСимвол '" << sym << "' последний раз встречается на " << strRchr(test1, sym)  << " позиции\n";
    cout << "\nВаша строка после обработки: ";
    printLine(test1);
    cout << "\n";
}

int strlen(char words[]){
    int i = 0;
    while (words[i]){
        i++;
    }
    return i;
}

void printLine (char a[]){
    for (int i = 0; a[i]; i++){
        cout << a[i];
    }

}

int deleteSymbols(char a[], int start, int end){ //удаляет элементы со start(включая)  до end (включая). start - это index элемента (в массиве)

    if ((start > (strlen(a))) || (start < 0) || (end < 0) || (start > end)){
        return 0;
    }
    for (int i = start; a[i]; i++){
        a[i] = a[i + end - start + 1];
    }
    return 1;

}

int deleteRepeatSymbol (char a[], char sym){
    int flag = 0;
    for (int i = 0; a[i]; i++){
        while(a[i] == sym){
            if (!flag){
                flag = 1;
                i++;
                continue;
            }
            deleteSection(a, i, 1);
        }
    }
    if (flag) return 1;
    else return 0;
}

int deleteSymbol (char a[], char sym){

    int flag = 0;
    for (int i = 0; a[i]; i++){
        while(a[i] == sym){
            deleteSection(a, i, 1);
                flag = 1;
        }
    }
    if (flag) return 1;
    else return 0;
}

int deleteRepeat (char a[]){
    int flag = 0;
    for (int i = 0; a[i]; i++){
        for (int j = i + 1; a[j]; j++){
            while (a[i] == a[j]){
                flag = 1;
                deleteSection(a, j, 1);
            }
        }
    }
    if (flag) return 1;
    else return 0;
}

int deleteBesidesRepeat (char a[]){
    int flag = 0;
    for (int i = 0; a[i]; i++){
        if (a[i] == a[i + 1]) {
            while (a[i] == a[i + 1]) deleteSection(a, i, 1);
            flag = 1;
        }
    }
    if (flag == 1) return 1;
    else return 0;
}

void deleteSection(char a[], int start, int lenght){ //start - это индекс элемента в массиве
     int i = start;
     for (i; a[i]; i++) a[i] = a[i + lenght];
     a[i] = 0;
}

void strcpy(char str1[], char str2[]){
    for (int i = 0; str2[i - 1]; i++) str1[i] = str2[i];
}

int strchr(char str[], char sym){
    for (int i = 0; str[i]; i++){
        if (str[i] == sym) return i;
    }
    return NULL;
}

int strRchr(char str[], char sym){
    for (int i = strlen(str); i >= 0; i--){
        if (str[i] == sym) return i;
    }
    return NULL;
}

void  strNcpy(char str1[], char str2[], int size){
    int i = 0;
    for (i; (i + 1) <= size; i++) str1[i] = str2[i];
    str1[i] = '\0';
}

void strcat(char str1[], char str2[]){
    for (int i = strlen(str1), j = 0; str2[j - 1]; i++, j++){
        str1[i] = str2[j];
    }
}

void strNcat(char str1[], char str2[], int size){
    int i = strlen(str1), j = 0;
    for (i; (j + 1) <= size ; i++, j++){
        str1[i] = str2[j];
    }
    str1[i] = '\0';
}
