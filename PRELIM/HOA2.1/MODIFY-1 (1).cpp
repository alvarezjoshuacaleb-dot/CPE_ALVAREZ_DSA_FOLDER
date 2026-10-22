#include <iostream>
#include <string>

class Student {
private:
    std::string studentName;
    int studentAge;

public:
    // Constructor
    Student(std::string newName = "John Doe", int newAge = 18) {
        studentName = newName;
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
    }

    // Copy Constructor
    Student(const Student &copyStudent) {
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
        std::cout << "Copy Constructor Called." << std::endl;
    }

    // Destructor
    ~Student() {
        std::cout << "Destructor Called." << std::endl;
    }

    void printDetails() {
        std::cout << "Name: " << studentName << ", Age: " << studentAge << std::endl;
    }
};

int main() {
    const int j = 5;
    std::string nameList[j] = {"Alejado", "Aguila", "Alvarez", "Abello", "Baltazar"};
    int ageList[j] = {21, 19, 19, 19, 16};

    Student studentList[j]; // array of Student objects

    // Loop A: Assign values to each student
    for (int i = 0; i < j; i++) {
        studentList[i] = Student(nameList[i], ageList[i]);
    }

    // Loop B: Display student details
    for (int i = 0; i < j; i++) {
        studentList[i].printDetails();
    }

    return 0;
}
