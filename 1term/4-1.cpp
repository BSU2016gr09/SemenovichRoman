//Сумма и разность чисел, представленных в виде массива
#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void initA(int A[], int N);
void initA(int A[], int N, int init);
void inputArray(int A[], int N);
void printA(int A[], int N) ;
void sum(int rez[], int A[], int B[], int N);
void difference(int rez[], int A[], int B[], int N);
bool checkTwoNumbers(int A[], int B[]);

int main()
{
    setlocale(LC_ALL, "russian");
    const int MAXSIZE = 4;
    int A[MAXSIZE], B[MAXSIZE], rez[MAXSIZE], init = 0;
    inputArray(A, MAXSIZE);
    inputArray(B, MAXSIZE);
    //sum(rez, A, B, MAXSIZE);
    //difference(rez, A, B, MAXSIZE);
}


void initA(int A[], int N)
{
    int i = 0;
    while (i < N)	A[i++] = 0;
}

void initA(int A[], int N, int k)
{
    int i = 0;
    while (i < N)	A[i++] = k;
}

void printA(int A[], int N)
{
    int i = 0;
    while (i < N) cout << A[i++];
    cout << '\n';
}

void inputArray(int A[], int N)
{
    cout << "\nВведите число: \n";
    int i = 0;
    while (i < N) cin >> A[i++];
}


void sum(int rez[], int A[], int B[], int N)
{
    int i = N-1, tmp = 0;
    while (i>=0)
    {
        rez[i] =((A[i]+B[i])% 10)+tmp;
        tmp = (A[i] + B[i]) / 10;
        i--;
    }
    cout << "\nСумма чисел:\n";
    printA(rez, N);
}

void difference(int rez[], int A[], int B[], int N){
    int i = N - 1;
    if (checkTwoNumbers(A, B)){
        while (i >= 0){
            if (A[i] < B[i]) {
                A[i] += 10;
                A[i - 1] -= 1;
            }
            rez[i] = A[i] - B[i];
            i--;
        }
        cout << "\nРазность чисел:\n";
        printA(rez, N);
    }
    else {
        while (i >= 0){
            if (B[i] < A[i]) {
                B[i] += 10;
                B[i - 1] -= 1;
            }
            rez[i] = B[i] - A[i];
            i--;
        }
        cout << "\nРазность чисел:\n-";
        printA(rez, N);
    }
}

bool checkTwoNumbers(int A[], int B[]){
    int i = 0;
    while (A[i] == B[i]) i++;
    if (A[i] >= B[i]) return true;
    else return false;
}
