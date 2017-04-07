//квадратные уравнения

#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;

class Quadratic{
    public:
        double a;
        double b;
        double c;
    //нет конструкторов...
        void calcDiscriminant(){
            discriminant = b * b - 4 * a * c;
            cout << "Дискриминант уравнения равен " << discriminant << "\n";

        }
        void calcRoots(){//А откуда эта функция знает про значение дискриминанта? Вдруг он еще не вычислен!!!!
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
        Quadratic sum(Quadratic other){
            Quadratic result;
            result.a = this->a + other.a;
            result.b = this->b + other.b;
            result.c = this->c + other.c;
            return result;
        }
        Quadratic difference(Quadratic other){
            Quadratic result;
            result.a = this->a - other.a;
            result.b = this->b - other.b;
            result.c = this->c - other.c;
            return result;
        }
    private:
        double x1, x2;
        double discriminant;
};

int main(){
    Quadratic q;
    Quadratic w;
    Quadratic e;
    q.a = 10;
    q.b = 9;
    q.c = -1;
    q.printQuadratic();
    q.calcDiscriminant();//По моему неудачная реализация. Пользователь вообще не должен знать про дискриминант. А может он по другим формулам считал всегда!!!
    q.calcRoots();
    w = q;
    e = q.sum(w);
    e = e.sum(w);
    e = e.difference(w);
    e.printQuadratic();
    e.calcDiscriminant();
    e.calcRoots();
} 
