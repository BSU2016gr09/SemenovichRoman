/*В тексте удалить фрагменты, заключённые в круглые скобки (скобка может начинаться в одной строке, а заканчиваться - другой).
Придумать свои функции*/

#include <iostream>
#include <time.h>
#include <fstream>
#include <string.h>

using namespace std;

void giveMemory(char *&, int);
void deleteMemory(char *&);
int fileSize();
void checkOpen();
void deleteBetweenBrackets(char *, int);
void showText(char *, int);
void fff(char *, int);

ifstream fin("text.txt", ios_base::in);
ofstream fout("result.txt", ios_base::trunc);

typedef void (*pFun)(char *, int);

int main(){
    checkOpen();

    char * text;
    int size = fileSize();
    pFun menu[] = {deleteBetweenBrackets, showText, fff};
    int choose;
    cout << "0. Удалить из текста фрагменты в скобках; 1. Показать текст; 2.Ничего не делать:";
    cin >> choose;
    giveMemory(text, size);
    fin.getline(text, size, '\0');

    (*menu[choose])(text, size);

    deleteMemory(text);

    fin.close();
    fout.close();
}

void giveMemory(char * &text, int size){
    try{
        text = new char[size];
    }
    catch(...){
        cout << "Память не выделилась :(";
        exit(0);
    }
}

void deleteMemory(char *& text){
    delete [] text;
    text = nullptr;
}

int fileSize(){
    int size;
    FILE * pFile = fopen("text.txt", "rb");
    fseek(pFile, 0, SEEK_END);
    size = ftell(pFile);
    fclose(pFile);
    return size;
}

void checkOpen(){
    if (!fin.is_open()){
           cout << "Файл text.txt не может быть открыт!\n";
           exit(0);
    }
}

void deleteBetweenBrackets(char * text, int size){
    char * begin;
    char * end;
    begin = strchr(text, '(');
    end = strchr(text, ')') + 1;
    if (begin != 0 & end != 0){

        char * tmp;
        giveMemory(tmp, size);
        strncat(tmp, text, begin - text);

        while(begin != 0 & end != 0){
            begin = strchr(end, '(');
            strncat(tmp, end, begin - end);
            end = strchr(end, ')') + 1;
        }
            fout << tmp;
            deleteMemory(tmp);
    }
    else fout << text;
}

void showText(char * text, int size){
    cout << text << "\n";
}

void fff(char * text, int size){
    return;
}
