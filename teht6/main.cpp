#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;

bool nameComp(Student a, Student b){
    return (a.getName() < b.getName());
}

bool ageComp(Student a, Student b){
    return (a.getAge() < b.getAge());
}

int main ()
{
    int selection = 0;
    vector<Student>studentList;

    do
    {
        cout << endl;
        cout << "Select" << endl;
        cout << "0 Add students" << endl;
        cout << "1 Print all students" << endl;
        cout << "2 Sort and print students according to Name" << endl;
        cout << "3 Sort and print students according to Age" << endl;
        cout << "4 Find and print student" << endl;
        cin >> selection;

        string student_name;
        int student_age;

        switch(selection)
        {
            case 0:
                // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
                cout << "   Give student name: ";
                cin >> student_name;
                cout << "   Give student age: ";
                cin >> student_age;

                // Lisää uusi student StudentList vektoriin.
                studentList.push_back(Student(student_name, student_age));
                break;
            case 1:
                // Tulosta StudentList vektorin kaikkien opiskelijoiden
                // nimet.
                for (auto i : studentList)
                {
                    cout << "   " << i.getName() << endl;
                }
                break;

            case 2:
                // Järjestä StudentList vektorin Student oliot nimen mukaan
                // algoritmikirjaston sort funktion avulla
                sort(studentList.begin(), studentList.end(), nameComp);
                // ja tulosta printStudentInfo() funktion avulla järjestetyt
                // opiskelijat
                for (auto i : studentList)
                {
                    i.printStudentInfo(1);
                }
                break;

            case 3:
                // Järjestä StudentList vektorin Student oliot iän mukaan
                // algoritmikirjaston sort funktion avulla
                sort(studentList.begin(), studentList.end(), ageComp);
                // ja tulosta printStudentInfo() funktion avulla järjestetyt
                // opiskelijat
                // opiskelijat
                for (auto i : studentList)
                {
                    i.printStudentInfo(1);
                }
                break;
            case 4:
                // Kysy käyttäjältä opiskelijan nimi
                cout << "   Give student name to search: ";
                cin >> student_name;
                // Etsi studentListan opiskelijoista algoritmikirjaston
                // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
                {
                    auto it = find_if(studentList.begin(), studentList.end(), [student_name](Student& student){
                        return (student.getName() == student_name);
                    });

                    if (it != studentList.end()){
                        it -> printStudentInfo(2);
                    }
                }
                // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
                break;
            default:
                cout<< "Wrong selection, stopping..."<<endl;
                break;
        }
    }while(selection < 5);

    return 0;
}
