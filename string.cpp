/*В тексте удалить фрагменты, заключённые в круглые скобки (скобка может начинаться в одной строке, а заканчиваться - другой).
Придумать свои функции*/

#include <iostream>
#include <time.h>
#include <fstream>
#include <string.h>

using namespace std;

void giveMemory(char *&, int);
void deleteMemory(char *&);
void deleteBetweenBrackets(char *, string);
void deleteAndWrite(char*, char *);
void fff(char *, string);

ifstream file("text.txt");
ifstream fin("text.txt", ios_base::in);
ofstream fout("result.txt", ios_base::trunc);

typedef void (*pFun)(char *, string);

int main(){
    if (fin.is_open() && file.is_open()){
        string tmp;
        char * text;
        int choose;
        pFun menu[] = {deleteBetweenBrackets, fff};

        cout << "0. Удалить из текста фрагменты в скобках; 1.Ничего не делать:\n";
        cin >> choose;
        (*menu[choose])(text, tmp);

        file.close();
        fin.close();
        fout.close();
    }
    else cout << "Файл не может быть открыт :(\n";
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

void deleteBetweenBrackets(char * text, string tmp){
    int size = 0;
    char * result;
    while(getline(file, tmp)){
        size = tmp.length() + 1;
        giveMemory(text, size);
        fin.getline(text, size);
        giveMemory(result, size);
        deleteAndWrite(text, result);
        deleteMemory(text);
        deleteMemory(result);
    }
}

void deleteAndWrite(char * text, char * result){
    char * old = text;
    char * opnBracket = strchr(text, '(');
    char * clsBracket = strchr(text, ')');
    static int count = 0;
    static int oldRow = 0;
    if(opnBracket && !oldRow) count++;
    if(clsBracket && !oldRow) count--;
    if(!opnBracket && !clsBracket && !count){
        fout << text << '\n';
        return;
    }
    while(opnBracket || clsBracket){
        if(opnBracket && !oldRow && !count){
            oldRow = 1;
        }
        if(clsBracket && count){
            clsBracket = strchr(clsBracket + 1, ')');
            if(clsBracket) count--;
        }
        if(opnBracket > old && (count == 1 || !count) && oldRow) strncat(result, old, opnBracket - old);
        if(clsBracket && !count){
            old = clsBracket + 1;
            clsBracket = strchr(old, ')');
            if(clsBracket) count--;
        }
        if(opnBracket){
            opnBracket = strchr(opnBracket + 1, '(');
            if(opnBracket) count++;
        }
        if(!opnBracket && !count) strcat(result, old);
    }
    oldRow = 0;
    if(count){
        fout << result;
        return;
    }
    fout << result << '\n';
}

void fff(char * text, string tmp){
    return;
}
