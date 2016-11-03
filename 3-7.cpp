#include <QCoreApplication>
#include <iostream>

using namespace std;

void push(int queue[], int N, int &top, int element);
void pop(int &top, int tail, int queue[]);
bool isFull(int top);
bool isEmpty(int top, int tail);
void showQueue(int queue[], int N);
void fillQueue(int queue[], int N);

int main(){
    int N = 4, top = N, tail = N - 1, element = 1;
    int queue[N];
    fillQueue(queue, N);
    cout<<"Пустая ";
    showQueue(queue, N);
    push(queue, N, top, element);
    cout<<"\n\nПосле добавления первого по счету элемента ";
    showQueue(queue, N);
    element++;
    push(queue, N, top, element);
    cout<<"\nПосле добавления второго элемента ";
    showQueue(queue, N);
    element++;
    push(queue, N, top, element);
    cout<<"\nПосле добавления третьего элемента ";
    showQueue(queue, N);
    pop(top, tail, queue);
    cout<<"\nПосле обработки первого пришедшего в очередь элемента ";
    showQueue(queue, N);
    pop(top, tail, queue);
    cout<<"\nПосле обработки второго пришедшего элемента ";
    showQueue(queue, N);
    element++;
    push(queue, N, top, element);
    cout<<"\nПосле добавления четвертого элемента ";
    showQueue(queue, N);
    element++;
    push(queue, N, top, element);
    cout<<"\nПосле добавления пятого элемента ";
    showQueue(queue, N);
    element++;
    push(queue, N, top, element);
    cout<<"\nПосле добавления шестого элемента ";
    showQueue(queue, N);
    cout<<"\n\nДобавление в заполненую очередь элемента:";
    push(queue, N, top, element);
    showQueue(queue, N);
    cout<<"\n\nОбработка всей очереди:";
    pop(top, tail, queue);
    pop(top, tail, queue);
    pop(top, tail, queue);
    pop(top, tail, queue);
    cout<<"\nОбработанная ";
    showQueue(queue, N);
    cout<<"\n";
}


void push(int queue[], int N, int &top, int element){
    if (isFull(top) == true){
        cout<<"\nНевозможно добавить. Очередь переполнена. ";
        return;
    }
    int i = 0;
    while (i <= N - 1){
        queue[i] = queue[i + 1];
        i++;
    }
    top--;
    queue[N - 1] = element;

}

void pop(int &top, int tail, int queue[]){
    cout<<"\n"<<"Обработанный элемент: "<<queue[top];
    queue[top] = 0;
    top++;
    if (isEmpty(top, tail) == true){
        cout<<"\nОчередь пуста";
    }
}

bool isEmpty(int top, int tail){
    if (top == tail + 1)
    return true;
    else return false;
}

bool isFull(int top){
    if (top == 0) return true;
    else return false;
}

void showQueue(int queue[], int N){
    int i = 0;
    cout<<"очередь: ";
    while(i < N){
        cout<<queue[i]<<" ";
        i++;
    }
}

void fillQueue(int queue[], int N){
    int i = 0;
    while (i < N){
        queue[i] = 0;
        i++;
    }
}
