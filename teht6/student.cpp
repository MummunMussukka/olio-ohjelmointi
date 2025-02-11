#include "student.h"

Student::Student(string nm, int a) {
    name = nm;
    age = a;
}

int Student::getAge(){
    return age;
}

string Student::getName(){
    return name;
}

void Student::setAge(int a){
    age = a;
}

void Student::setName(string nm){
    name = nm;
}

void Student::printStudentInfo(int indentations){
    for (int i = 0; i < indentations; i++){
        cout << "   ";
    }
    cout << "Name: " << name << endl;
    for (int i = 0; i < indentations; i++){
        cout << "   ";
    }
    cout << "   Age: " << age << endl;
}
