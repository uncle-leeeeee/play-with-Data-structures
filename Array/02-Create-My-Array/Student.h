#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int score;

public:
    Student(string studentName = "", int studentScore = 0)
    {
        name = studentName;
        score = studentScore;
    }
    //这里是ostream不是iostream
    friend ostream &operator<<(ostream &a, Student &student)
    {
        a << "name: " << student.name << ", "
          << " score: " << student.score << endl;
        return a;
    }
};