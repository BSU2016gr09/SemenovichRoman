//подсчитать количество элементов, встречающихся более одного раза
#include <QCoreApplication>
#include <iostream>
#include <ctime>

using namespace std;

void createArray(int a[], int N);
void printArray(int a[], int N);
void checkElements(int a[], int N);
void sortArray(int array[], int N);

int main(){
    srand(time(NULL));
    const int N = 5;
    int a[N];
    createArray(a, N);
    cout<<"Массив: ";
    printArray(a, N);
    sortArray(a, N);
    checkElements(a, N);
    return 0;
}

void createArray(int a[], int N){
    int i = 0, MAX_RAND = 10;
    while (i < N){
        a[i] = rand() % (MAX_RAND + 1);
        i++;
    }
}

void printArray(int a[], int N){
    int i = 0;
    while (i < N){
        cout<<a[i]<<" ";
        i++;
    }
    cout<<"\n";
}


void sortArray(int array[], int N){

    for(int i = 0; i < N - 1; ++i)
        {
            for(int j = 0; j < N - 1; ++j)// что за ужасный алгоритм сортировки???? Мы его 2 раза улучшали!!!!!!
            {
                if (array[j + 1] < array[j])
                {
                    swap(array[j],array[j+1]);
                }
            }
        }
}


void checkElements(int a[], int N){
    int i = 0; int flag = 0, result = 0;
    while (i < N){
        if (a[i] == a[i + 1]){
                flag++;
    }
        else{   if(flag != 0){
                result++;
            }
            flag = 0;
        }
        i++;
}
        cout<<"Количество элементов, встречающихся более одного раза: "<<result<<"\n";
}
