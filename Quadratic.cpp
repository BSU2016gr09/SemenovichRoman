//Доделать свои проекты с дополнительной реализацией конструкторов, деструкторов и операций =, +,-

//Квадратные уравнения

#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;

void giveMemory(double *&, int);
void deleteMemory(double *&);

class Quadratic{
    public:
        Quadratic():  a(1), b(1), c(1){
            cout << "Работает конструктор по умолчанию\n";
            calcRoots();
        }
        Quadratic(double a, double b, double c): a (a), b (b), c (c){
            if (!a){
                cout << "Попытка превратить квадратное уравнение в линейное\nИзмените первый коэффициент";
                exit(0);
            }
            cout << "Работает конструктор с параметрами\n";
            calcRoots();
        }
        ~Quadratic(){
            cout << "Работает деструктор\n";
            deleteMemory(roots);
        }

        friend Quadratic& operator+(Quadratic &left, Quadratic &right);
        friend Quadratic& operator-(Quadratic &left, Quadratic &right);

        Quadratic& operator=(Quadratic &other){
            this->a = other.a;
            this->b = other.b;
            this->c = other.c;
            deleteMemory(this->roots);
            this->calcRoots();
            return *this;
        }
        double * getRoots(){
            if (!roots[0]) cout << "Уравнение не имеет корней\n";
            return roots;
        }
        void setFirstCoefficient(double coefficient){
            while(!coefficient){
                cout << "Попытка превратить квадратное уравнение в линейное\nВведите первый коэффициент заново: ";
                cin >> coefficient;
            }
            this->a = coefficient;
            this->calcRoots();
        }
        void setSecondCoefficient(double coefficient){
            this->b = coefficient;
            this->calcRoots();
        }
        void setThirdCoefficient(double coefficient){
            this->c = coefficient;
            this->calcRoots();
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
        void printQuadratic(){
            cout << a << "x^2 + (" << b << "x) + (" << c << ") = 0\n";
        }
    private:
        double a;
        double b;
        double c;
        double * roots = nullptr; //В первую ячейку будет записываться количество корней
        void calcRoots(){
            if (roots != nullptr) deleteMemory(roots);
            if(!a){
                cout << "Попытка работы с линейным уравнением\n";
                exit(0);
            }
            double discriminant;
            discriminant = b * b - 4 * a * c;
            if (discriminant < 0){
                giveMemory(roots, 1);
                roots[0] = 0;
                return;
            }
            if (discriminant == 0){
                giveMemory(roots, 2);
                roots[0] = 1;
                roots[1] = -b / (2 * a);
                return;
            }
            if (discriminant > 0){
                giveMemory(roots, 3);
                roots[0] = 2;
                double sqrtDiscriminant = sqrt(discriminant);
                roots[1] = (-b + sqrtDiscriminant) / (2 * a);
                roots[2] = (-b - sqrtDiscriminant) / (2 * a);
                return;
            }
        }
};

void giveMemory(Quadratic *&);
void deleteMemory(Quadratic *&);

Quadratic& operator+(Quadratic &left, Quadratic &right){
    Quadratic * tmp;
    giveMemory(tmp);
    tmp->a = left.a + right.a;
    tmp->b = left.b + right.b;
    tmp->c = left.c + right.c;
    tmp->calcRoots();
    return *tmp;
}

Quadratic& operator-(Quadratic &left, Quadratic &right){
    Quadratic * tmp;
    giveMemory(tmp);
    tmp->a = left.a - right.a;
    tmp->b = left.b - right.b;
    tmp->c = left.c - right.c;
    tmp->calcRoots();
    return *tmp;
}

int main(){
    Quadratic first (1, 2 ,3);
    Quadratic second;
    Quadratic third;
    Quadratic * fourth;
    Quadratic * fifth;
    Quadratic * sixth;

    giveMemory(fourth);
    fourth->setFirstCoefficient(0);
    fourth->setSecondCoefficient(45);
    fourth->setThirdCoefficient(10);

    cout << "______________________________\nПервое уравнение:\n";
    first.printQuadratic();
    cout << "Корни первого уравнения:\n";
    double * firstRoots = first.getRoots();
    for (int i = 1; i <= firstRoots[0]; i++){
        cout << firstRoots[i] << '\n';
    }

    cout << "______________________________\nВторое уравнение:\n";
    second.setSecondCoefficient(-8);
    second.printQuadratic();
    cout << "Корни второго уравнения:\n";
    double * secondRoots = second.getRoots();
    for (int i = 1; i <= secondRoots[0]; i++){
        cout << secondRoots[i] << '\n';
    }

    cout << "______________________________\nТретье уравнение (сумма 1-го и 4-го):\n";
    third = (first + *fourth);
    third.printQuadratic();
    cout << "Корни третьего уравнения:\n";
    double * thirdRoots = third.getRoots();
    for (int i = 1; i <= thirdRoots[0]; i++){
        cout << thirdRoots[i] << '\n';
    }

    cout << "______________________________\nЧетвертое уравнение:\n";
    fourth->printQuadratic();
    cout << "Корни четвертого уравнения:\n";
    double * fourthRoots = fourth->getRoots();
    for (int i = 1; i <= fourthRoots[0]; i++){
        cout << fourthRoots[i] << '\n';
    }

    cout << "______________________________\nПятое уравнение (1-е):\n";
    giveMemory(fifth);
    *fifth = first;
    fifth->printQuadratic();
    cout << "Первый коэффициент: " << fifth->getFirstCoefficient() << "\n";
    cout << "Второй коэффициент: " << fifth->getSecondCoefficient() << "\n";
    cout << "Третий коэффициент: " << fifth->getThirdCoefficient() << "\n";
    cout << "Корни пятого уравнения:\n";
    double * fifthRoots = fifth->getRoots();
    for (int i = 1; i <= fifthRoots[0]; i++){
        cout << fifthRoots[i] << '\n';
    }

    cout << "______________________________\nШестое уравнение (разность 3-го и два раза 5-го):\n";
    giveMemory(sixth);
    *sixth = (third - *fifth - *fifth);
    sixth->printQuadratic();
    cout << "Корни шестого уравнения:\n";
    double * sixthRoots = sixth->getRoots();
    for (int i = 1; i <= sixthRoots[0]; i++){
        cout << sixthRoots[i] << '\n';
    }
    cout << "______________________________\n";

    deleteMemory(fourth);
    deleteMemory(fifth);
    deleteMemory(sixth);
}

void giveMemory(Quadratic * &object){
    try{
        object = new Quadratic;
    }
    catch(...){
        cout << "Память не выделилась :(\n";
        exit(0);
    }
}

void deleteMemory(Quadratic * &object){
    delete object;
    object = nullptr;
}

void giveMemory(double *& array, int size){
    try{
        array = new double [size];
    }
    catch(...){
        cout << "Память не выделилась :(\n";
        exit(0);
    }
}

void deleteMemory(double *& array){
    delete [] array;
    array = nullptr;
}
