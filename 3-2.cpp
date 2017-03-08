//(Указатели на столбцы.) В массиве А(N,M) расположить столбцы по возрастанию значений минимальных элементов столбцов.

#include <iostream>
#include <time.h>

using namespace std;

void give_memory(int**&, int, int);
void printArray(int **, int, int);
void initArray(int **, int, int);
void delete_memory(int**, int);
void delete_memory(int*);
int findMin(int *, int);
void sortArray(int **, int *, int, int);
void saveMin(int **, int *, int, int);
int rand0m();

int main(){
    int M;
    int N;
    cout << "Введите ширину: ";
    cin >> M;
    cout << "Введите высоту: ";
    cin >> N;
    int** arr;
    int * minArr;
    give_memory(arr, N, M);
    initArray(arr, N, M);
    printArray(arr, N, M);
    sortArray(arr, minArr, N, M);
    printArray(arr, N, M);
    delete_memory(arr, M);
    delete_memory(minArr);
    arr = nullptr;
    minArr = nullptr;
}

int rand0m(){
    static int number = time(NULL) % 100000;
    int a = 13;
    int b = 15;
    int c = 5;
    number ^= number << a;
    number ^= number >> b;
    number ^= number << c;
    return number;
}

void sortArray(int ** arr, int * minArr, int N, int M){
    saveMin(arr, minArr, N, M);
    int * tmp;
    for(int i = 0; i < M; i++) {
        for(int j = M - 1; j > i; j--) {
            if ( minArr[j-1] > minArr[j]) {
                swap(minArr[j-1], minArr[j]);
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

int findMin(int * arr, int N){
    int min = arr[0];
    for (int i = 1; i < N; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

void saveMin(int ** arr, int * minArr, int N, int M){
    for(int i = 0; i < M; i++){
        minArr[i] = findMin(arr[i], N);
    }
}

void give_memory(int ** &arr, int N, int M){
    try {
        arr = new int *[M];
        for (int i = 0; i < M; i++) {
            arr[i] = new int[N];
        }
    }
    catch (...) {
        cout << "Память не выделилась ";
        exit(0);
    }
}

void printArray(int** arr, int N, int M){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout.width(4);
            cout << arr[j][i];
        }
        cout << endl;
    }
    cout << endl;
}

void initArray(int** arr, int N, int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            arr[j][i] = rand0m() % 100;
        }
    }
}

void delete_memory(int** arr, int M) {
    for (int i = 0; i < M; i++){
        delete [] arr[i];
    }
    delete [] arr;
}

void delete_memory(int * arr){
    delete [] arr;
}
