#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define c cout
#define e endl

//struct Student {
//    string surname;
//    string group;
//    int grades[5];
//
//    bool isExcellent() {
//        int count = 0;
//        for (int grade : grades)
//            if (grade == 5) count++;
//        return count >= 4;
//    }
//
//    bool isPoor() {
//        int count = 0;
//        for (int grade : grades)
//            if (grade == 2 || grade == 3) count++;
//        return count > 2;
//    }
//};
//
//void printStudent(const Student& s) {
//    c << "Фамилия: " << s.surname << ", Группа: " << s.group << ", Оценки: ";
//    for (int grade : s.grades) c << grade << " ";
//    c << e;
//}
//
//int main() {
//    system("chcp 1251>null");
//
//    int size = 2;
//    Student* students = new Student[size]{
//        {"Иванов", "A1", {5, 5, 4, 5, 5}},
//        {"Петров", "B2", {3, 2, 3, 4, 3}}
//    };
//
//    c << "Отличники:" << e;
//    for (int i = 0; i < size; i++)
//        if (students[i].isExcellent()) printStudent(students[i]);
//
//    c << e << "Двоечники:" << e;
//    for (int i = 0; i < size; i++)
//        if (students[i].isPoor()) printStudent(students[i]);
//
//    delete[] students;
//    return 0;
//}




struct Man {
    string surname;
    string name;
    int age;
    string birthDate;
};

void printMan(const Man& m) {
    c << "Фамилия: " << m.surname << ", Имя: " << m.name
        << ", Возраст: " << m.age << ", Дата рождения: " << m.birthDate << e;
}

void sortByName(vector<Man>& people) {
    sort(people.begin(), people.end(), [](const Man& a, const Man& b) {
        return a.name < b.name;
        });
}

void searchBySurname(const vector<Man>& people, string surname) {
    for (const auto& m : people)
        if (m.surname == surname) printMan(m);
}

int main() {
    system("chcp 1251>null");

    vector<Man> people = {
        {"Иванов", "Алексей", 25, "15.02.1999"},
        {"Петров", "Борис", 30, "03.03.1994"},
        {"Сидоров", "Виктор", 40, "15.02.1984"}
    };

    c << "Сортировка по имени:" << e;
    sortByName(people);
    for (const auto& p : people) printMan(p);

    string month = "02";
    c << e << "Именинники месяца " << month << ":" << e;
    for (const auto& p : people)
        if (p.birthDate.substr(3, 2) == month) printMan(p);

    return 0;
}