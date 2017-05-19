#include <QCoreApplication>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

const int MARKS_SIZE = 5;
const int GROUPS = 9;
const int COURSES_NUMBER = 5;

class Student{
public:
    Student(): course(0), group(0), stipend(0), average(0){
        cout << "Работает конструктор по умолчанию\n";
        giveMemory(surname, 0);
        giveMemory(name, 0);
        giveMemory(patronymic, 0);
        for(int i = 0; i < MARKS_SIZE; i++) marks[i] = 0;
    }
    Student(char * surname, char * name, char * patronymic, int course, int group, int marks[]): average(0){
        cout << "Работает конструктор с параметрами\n";

        setString(this->surname, surname);
        setString(this->name, name);
        setString(this->patronymic, patronymic);
        setCourse(course);
        setGroup(group);
        setMarks(marks);
    }
    Student(char *surname, char *name, char *patronymic, int course, int group): average(0){
        cout << "Работает конструктор с параметрами\n";

        setString(this->surname, surname);
        setString(this->name, name);
        setString(this->patronymic, patronymic);
        setCourse(course);
        setGroup(group);
        int marks[MARKS_SIZE];
        for(int i = 0; i < MARKS_SIZE; i++) marks[i] = 0;
        setMarks(marks);
    }
    Student(const Student& other){
        cout << "Работает конструктор копирования\n";

        this->setString(this->surname, other.surname);
        this->setString(this->name, other.name);
        this->setString(this->patronymic, other.patronymic);
        this->setCourse(other.course);
        this->setGroup(other.group);
        this->setMarks((int *)other.marks);
        this->average = other.average;
    }

    ~Student(){
        cout << "Работает деструктор\n";
        deleteMemory(surname);
        deleteMemory(name);
        deleteMemory(patronymic);
    }

    Student& operator =(const Student& other){
        this->setString(this->surname, other.surname);
        this->setString(this->name, other.name);
        this->setString(this->patronymic, other.patronymic);
        this->setCourse(other.course);
        this->setGroup(other.group);
        this->setMarks((int *)other.marks);
        this->average = other.average;
        return *this;
    }

    void setCourse(int course){
        if(course < 1 || course > COURSES_NUMBER){
            cout << "Неправильно введен курс\n";
            return;
        }
        this->course = course;
    }
    void setGroup(int group){
        if (group < 1 || group > GROUPS){
            cout << "Неправильно введена группа\n";
            return;
        }
        this->group = group;
    }
    void setMarks(int marks[]){
        for (int i = 0; i < MARKS_SIZE; i++){
            if (marks[i] < 0 || marks[i] > 10) cout << "Ошибка в оценках\n";
            this->marks[i] = marks[i];
            average += marks[i];
        }
        average /= MARKS_SIZE;
        calcStipend();
    }

    char * getSurname(){
        return this->surname;
    }
    char * getName(){
        return this->name;
    }
    char * getPatronymic(){
        return patronymic;
    }
    int getCourse(){
        return course;
    }
    int getGroup(){
        return group;
    }
    int * getMarks(){
        return marks;
    }
    double getAverage(){
        return average;
    }
    int getStipend(){
        return stipend;
    }
    int calcMinMark(){
        int min = 10;
        for(int j = 0; j < MARKS_SIZE; j++){
            if(marks[j] < min) min = marks[j];
        }
        return min;
    }
    friend ostream& operator << (ostream&, const Student&);
    friend istream& operator >> (istream&, Student&);

private:
    char * surname;
    char * name;
    char * patronymic;
    int course;
    int group;
    int marks[MARKS_SIZE];
    int stipend;
    double average;
    void giveMemory(char *&string, int size){
        try{
            string = new char[size];
        }
        catch(...){
            cout << "Память не выделилась :(";
            exit(0);
        }
    }
    void deleteMemory(char *&string){
        delete [] string;
        string = nullptr;
    }
    void setString(char * &dest, char * src){
        int size;
        size = strlen(src);
        if (!size){
            cout << "Отсутствует информация\n";
        }
        giveMemory(dest, size);
        strcpy(dest, src);
    }
    void calcStipend(){
        if (average < 5) stipend = 0;
        if (average > 4 && average < 9) stipend = 40;
        if (average > 8) stipend = 50;
    }

};


typedef void(*pFun)(vector <Student>&);

void showSessionResults(vector <Student>&);
void showBadResultsByCourses(vector<Student>&);
void printList(vector <Student>&);
void sortByAverage(vector <Student>&);
void sortByCoursesAndStipend(vector<Student>&);
void showHighAchievers(vector<Student> &);

int main(){
    int marks1[] = {9,9,9,9,9};
    Student a("First", "First", "First", 4, 4);
    Student b("Second", "Second", "Second", 4, 3, marks1);
    Student c("Second", "Second", "Seconw", 4, 3, marks1);
    int marks2[] = {7,10,9,8,8};
    Student d("Third", "Third", "Third", 2, 4, marks2);
    int marks3[] = {9, 10, 10, 9, 9};
    Student f("Fourth", "Fourth", "Fourth", 2, 4, marks3);
    Student g;
    //cin >> g;
    vector <Student> students;
    students.reserve(0);
    students.push_back(g);
    students.push_back(f);
    students.push_back(d);
    students.push_back(c);
    students.push_back(b);
    students.push_back(a);
    int choose;
    pFun menu[] = {printList, sortByAverage, sortByCoursesAndStipend, showSessionResults, showBadResultsByCourses, showHighAchievers};
    while (1){
        cout << "0. Показать список; 1.Сортировать по ср.баллу; 2.Сортировать по курсу и стипендии; 3.Результаты сессии; 4.Неудовлетворительные оценки по курсам; 5 Показать отличников по курсу (по алфавиту)\n";
        cin >> choose;
        (*menu[choose])(students);
    }
}

ostream& operator << (ostream &cout, const Student &student){
    cout << "Фамилия: " << student.surname << "\n";
    cout << "Имя: " << student.name << "\n";
    cout << "Отчество: " << student.patronymic << "\n";
    cout << "Курс: " << student.course << "\n";
    cout << "Группа: " << student.group << "\n";
    cout << "Оценки: "; for(int i = 0; i < MARKS_SIZE; i++) cout << student.marks[i] << " ";
    cout << "\nСредний балл: " << student.average << "\n";
    cout << "Стипендия: " << student.stipend << "$\n";
    cout << "___________________________________\n";
    return cout;
}

istream& operator >> (istream &cin, Student &student){
    cout << "Введите фамилию: ";
    char * tmp = new char[20];
    cin >> tmp;
    student.setString(student.surname, tmp);
    cout << "Введите имя: ";
    cin >> tmp;
    student.setString(student.name, tmp);
    cout << "Введите отчество: ";
    cin >> tmp;
    student.setString(student.patronymic, tmp);
    cout << "Введите курс: ";
    cin >> student.course;
    while(student.course > 5 || student.course < 1){
        cout << "Ошибка! Введите курс заново: ";
        cin >> student.course;
    }
    cout << "Введите оценки (" << MARKS_SIZE <<"): ";
    student.average = 0;
    for (int i = 0; i < MARKS_SIZE; i++){
        cin >> student.marks[i];
        while(student.marks[i] < 0 || student.marks[i] > 10){
            cout << "Ошибка! Введите оценку заново: ";
            cin >> student.marks[i];
        }
        student.average += student.marks[i];
    }
    student.average /= MARKS_SIZE;
    student.calcStipend();
    return cin;
}

void showSessionResults(vector <Student> &students){
    typedef void (*pF)(vector<Student>&);
    void perfect(vector<Student>&);
    void good(vector<Student>&);
    void normal(vector<Student>&);
    void bad(vector<Student>&);
    int choose;
    pF submenu[] = {perfect, good, normal, bad};
    cout << "0.Отлично; 1. Хорошо; 2. Удовлетворительно; 3.Неудовлетворительно\n: ";
    cin >> choose;
    if (choose < 0 || choose > 3) return;
    (*submenu[choose])(students);
}

void perfect(vector<Student> &students){
    cout << "______________\nОтлично:\n\n";
    for (unsigned int i = 0; i < students.size(); i++)
        if (students[i].calcMinMark() > 8) cout << students[i];
}

void good(vector<Student> &students){
    cout << "______________\nХорошо:\n\n";
    for (unsigned int i = 0; i < students.size(); i++)
        if (students[i].calcMinMark() > 6 && students[i].calcMinMark() < 9) cout << students[i];
}

void normal(vector<Student> &students){
    cout << "______________\nУдовлетворительно:\n\n";
    for (unsigned int i = 0; i < students.size(); i++)
        if (students[i].calcMinMark() > 3 && students[i].calcMinMark() < 7) cout << students[i];
}

void bad(vector<Student> &students){
    cout << "______________\nНеудовлетворительно:\n\n";
    for (unsigned int i = 0; i < students.size(); i++)
        if (students[i].calcMinMark() < 4 && students[i].getCourse()) cout << students[i];
}

void showBadResultsByCourses(vector<Student> &students){
    cout << "______________\nКоличество неудовлетворительных оценок:\n\n";
    int result[COURSES_NUMBER][GROUPS + 1];
    for (int i = 0; i < COURSES_NUMBER; i++)
        for (int j = 0; j < GROUPS + 1; j++) result[i][j] = 0;
    for (unsigned int i = 0; i < students.size(); i++){
        if (students[i].calcMinMark() < 4 && students[i].getCourse()){
            result[students[i].getCourse() - 1][students[i].getGroup()]++;
            result[students[i].getCourse() - 1][0]++;
        }
    }
    for (int i = 0; i < COURSES_NUMBER; i++){
        cout << "\n\n" << i + 1 << " курс(" << result[i][0] << "):\n\n";
        for (int j = 1; j < GROUPS + 1; j++) cout << j << " группа: " << result[i][j] << "\n";
    }
}

void printList(vector<Student> &students){
    for(unsigned int i = 0; i < students.size(); i++) cout << students[i];
}

void sortByAverage(vector<Student> &students){
    for(unsigned int i = 0; i < students.size() - 1; i++){
        if (!students.size()) break;
        for(unsigned int j = 0; j < students.size() - i - 1; j++){
            if (students[j].getAverage() > students[j + 1].getAverage()) swap(students[j], students[j + 1]);
        }
    }
}

void sortByCoursesAndStipend(vector<Student> &students){
    for(unsigned int i = 0; i < students.size() - 1; i++){
        if (!students.size()) break;
        for(unsigned int j = 0; j < students.size() - i - 1; j++){
            if (students[j].getCourse() > students[j + 1].getCourse()) swap(students[j], students[j + 1]);
            if (students[j].getCourse() == students[j + 1].getCourse() && students[j].getStipend() > students[j + 1].getStipend())
                swap(students[j], students[j + 1]);
        }
    }
}

void showHighAchievers(vector<Student> &students){
    vector <Student> courses[COURSES_NUMBER];
    for (int i = 0; i < COURSES_NUMBER; i++) courses[i].reserve(1);
    int position;
    for (unsigned int i = 0; i < students.size(); i++){
        if(students[i].calcMinMark() > 8){
            position = students[i].getCourse() - 1;
            courses[position].push_back(students[i]);
        }
    }
    void sortByAlphabet(vector <Student> *);
    sortByAlphabet(courses);
    for (unsigned int i = 0; i < COURSES_NUMBER; i++)
        for (unsigned int j = 0; j < courses[i].size(); j++) cout << courses[i][j];
}

void sortByAlphabet(vector <Student> courses[]){
    for (unsigned int i = 0; i < COURSES_NUMBER; i++)
        for (unsigned int j = 0; j < courses[i].size() - 1; j++){
            if (!courses[i].size()) break;
            for (unsigned int z = 0; z < courses[i].size() - j - 1; z++){
                if(strcmp(courses[i][z].getSurname(), courses[i][z + 1].getSurname()) > 0)
                    swap(courses[i][z], courses[i][z + 1]);
                else if(strcmp(courses[i][z].getSurname(), courses[i][z + 1].getSurname()) == 0)
                    if(strcmp(courses[i][z].getName(), courses[i][z + 1].getName()) > 0)
                        swap(courses[i][z], courses[i][z + 1]);
                    else if(strcmp(courses[i][z].getName(), courses[i][z + 1].getName()) == 0)
                        if(strcmp(courses[i][z].getPatronymic(), courses[i][z + 1].getPatronymic()) > 0)
                            swap(courses[i][z], courses[i][z + 1]);
            }
        }
}
