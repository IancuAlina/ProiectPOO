#pragma once
#include<string>
using namespace std;
class Student
{
private:
    string name;
    int marks;

public:
    string getname();
   
    int getmarks();
   
    void setname(string n);
   
    void setmarks(int m);
    
    Student(string n, int m);
   
    Student();
 
};