#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int score;

public:
    Student(string studentName, int studentScore)
    {
        name = studentName;
        score = studentScore;
    }
    friend iostream &operator<<(iostream &a, Student &student)
    {
        a << "name: " << student.name << ", "
          << " score: " << student.score << endl;
        return a;
    }
};