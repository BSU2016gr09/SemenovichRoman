//Доделать свои проекты с дополнительной реализацией конструкторов, деструкторов и операций =, +,-

//Квадратные уравнения

#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;

class Quadratic{
    public:
        Quadratic(){// прочитай в интернете, почему правильнее использовать списки инициализации. Т.е. делать так:  Quadratic():a(1), b(1), c(1){}
            a = 1;
            b = 1;
            c = 1;
            cout << "Работает конструктор по умолчанию\n";
        }
        Quadratic(double a, double b, double c){
            this->a = a;
            this->b = b;
            this->c = c;
            cout << "Работает конструктор по умолчанию\n";
        }
        ~Quadratic(){
            cout << "Работает деструктор по умолчанию\n";
        }
        friend Quadratic& operator+(Quadratic &left, Quadratic &right){//Прочитай в интернете почему выгоднее friend функция по сравнению с членом класса
            Quadratic * tmp;
            tmp->a = left.a + right.a;
            tmp->b = left.b + right.b;
            tmp->c = left.c + right.c;
            return *tmp;
        }
        friend Quadratic& operator-(Quadratic &left, Quadratic &right){//Прочитай в интернете почему выгоднее friend функция по сравнению с членом класса
            Quadratic * tmp;
            tmp->a = left.a - right.a;
            tmp->b = left.b - right.b;
            tmp->c = left.c - right.c;
            return *tmp;
        }
        Quadratic& operator=(Quadratic &other){
            this->a = other.a;
            this->b = other.b;
            this->c = other.c;
            return *this;
        }
        void setFirstCoefficient(double coefficient){
            this->a = coefficient;
        }
        void setSecondCoefficient(double coefficient){
            this->b = coefficient;
        }
        void setThirdCoefficient(double coefficient){
            this->c = coefficient;
        }
        double getFirstCoefficient(){
            return this->a;
        }
        double getSecondCoefficient(){
            return this->b;
        }
        double getThirdCoefficient(){
            return this->c;
        }
        void calcRoots(){
            double discriminant;
            discriminant = b * b - 4 * a * c;
            cout << "Дискриминант уравнения равен " << discriminant << "\n";
            if (discriminant < 0){
                cout << "Уравнение не имеет корней :( \n";
                return;
            }
            double sqrtDiscriminant = sqrt(discriminant);
            x1 = (-b + sqrtDiscriminant) / (2 * a);
            x2 = (-b - sqrtDiscriminant) / (2 * a);
            cout << "Корни уравнения равны: " << x1 << ", " << x2 << "\n";
        }
        void printQuadratic(){
            cout << a << "x^2 + (" << b << "x) + (" << c << ") = 0\n";
        }
    private:
        double a;
        double b;
        double c;
        double x1, x2;
};

void giveMemory(Quadratic *&);//глупая функция... Она всего то делает 1 строку и то без проверок ))))
void deleteMemory(Quadratic *&);//глупая функция...

int main(){
    Quadratic first (1, 2 ,3);
    Quadratic second;
    Quadratic third;
    Quadratic * fourth;
    Quadratic * fifth;
    Quadratic * sixth;

    giveMemory(fourth);
    fourth->setFirstCoefficient(8);
    fourth->setSecondCoefficient(2);
    fourth->setThirdCoefficient(10);

    cout << "______________________________\nПервое уравнение:\n";
    first.printQuadratic();
    first.calcRoots();

    cout << "______________________________\nВторое уравнение:\n";
    second.setSecondCoefficient(-8);
    second.printQuadratic();
    second.calcRoots();

    cout << "______________________________\nТретье уравнение (сумма 1-го и 4-го):\n";
    third = (first + *fourth);
    third.printQuadratic();
    third.calcRoots();

    cout << "______________________________\nЧетвертое уравнение:\n";
    fourth->printQuadratic();
    fourth->calcRoots();

    cout << "______________________________\nПятое уравнение (1-е):\n";
    *fifth = first;
    fifth->printQuadratic();
    cout << "Первый коэффициент: " << fifth->getFirstCoefficient() << "\n";
    cout << "Второй коэффициент: " << fifth->getSecondCoefficient() << "\n";
    cout << "Третий коэффициент: " << fifth->getThirdCoefficient() << "\n";
    fifth->calcRoots();

    cout << "______________________________\nШестое уравнение (разность 3-го и два раза 5-го):\n";
    *sixth = third - *fifth - *fifth;
    sixth->printQuadratic();
    sixth->calcRoots();
    cout << "______________________________\n";

    deleteMemory(fourth);
}

void giveMemory(Quadratic * &object){
    object = new Quadratic;
}

void deleteMemory(Quadratic * &object){
    delete object;
    object = nullptr;
}
