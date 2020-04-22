#include<iostream>
#include<vector>
#include<string>

struct Student{
    std::string name {};
    int grade {};
};

int main()
{
    std::vector<Student> student_list;
    std::string name;

    int student_num {0};
    
    std::cout << "Enter the number of students: ";
    std::cin >> student_num;
    
    // declare a single_student's structure
    Student single_student;

    for (int i {0}; i < student_num; ++i){

        std::cout << "Name: ";
        std::cin >> single_student.name;

        std::cout << "Grade: ";
        std::cin >> single_student.grade;

        student_list.push_back(single_student);
    }

    // print the student_list's information
    for (auto s : student_list){
        std::cout << "Name: " << s.name << '\n';
        std::cout << "Grade: " << s.grade << '\n';
        std::cout << "\n";
    }

    return 0;
}
