#include <iostream>
#include <string>

class Student{
    private:
        std::string studentName;
        int studentAge;

    public:
        //constructor
        Student(std::string newName = "John Doe", int newAge = 18){
            studentName = std::move(newName);
            studentAge = newAge;

            std::cout << "Constructor Called." << std::endl;
        }

        //destructor
        ~Student(){
            std::cout << "Destructor Called." << std::endl;
        }

        //Copy Constructor
        Student(const Student &copyStudent){
            std::cout << "Copy Constructor Called." << std::endl;
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
        }

        void printDetails(){
            std::cout << this->studentName << " " << this->studentAge << std::endl;
        }
};

int main(){
    const size_t j = 5;

    Student studentList[j] = {};
    std::string nameList[j] = {"Alejado","Aguila","Alvarez","Abello","Baltazar"};
    int ageList[j]={21,19,19,19,16};


    for(int i = 0; i < j; i++){//Loop A
        Student* ptr = new Student(nameList[i], ageList[i]);
        studentList[i] = *ptr;
    }

    for(int i = 0; i < j; i++){//Loop B 
        studentList[i].printDetails();

    }
    return 0;

}
