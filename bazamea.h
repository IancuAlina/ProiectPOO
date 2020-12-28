#pragma once
#include "Student.h"
#include<fstream>
class mydatabase
{
private:
    string filename;
    Student STUDENT[1000];
    int StudentsQuantity;
    fstream File;

public:
    mydatabase();
    ~mydatabase();
    void ReadData();

      void PrintData();

        void UpdateData();


        void WriteData();

        void RemoveStudent();

        void AddData();

        void RemoveAllData();

        void ChangeDatabaseFile();


        void menu();
   
};