// bazamea.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Student.h"
#include"bazamea.h"
#include <iostream>



string Student::getname()
{
    return name;
}
   
int Student::getmarks()
{
    return marks;
    }
   
    void Student::setname(string n)
    {
        name = n;
    }
    void Student ::setmarks(int m)
    {
        marks = m;

    }
    Student:: Student(string n,int m)
    {
        name = n;
        marks = m;
    }
    Student ::Student()
    {

    }


    mydatabase:: mydatabase()
    {
        filename = "Mydb.txt";
        StudentsQuantity = 0;
       
        menu();
        
    }
    mydatabase:: ~mydatabase()
    {
       
    }
    void mydatabase::ReadData()
    {
        StudentsQuantity = 0;
        string line; 
        ifstream File;
        File.open(filename,ios::app);
        while (getline(File, line))
        {
          
            STUDENT[StudentsQuantity].setname(line);
            
        
            getline(File, line);
         
            STUDENT[StudentsQuantity].setmarks(stoi(line));
            
            
        
            
            StudentsQuantity++;
            
        }
    }
    void mydatabase::PrintData()
    {
        cout << "Name\t\tMarks" << endl << endl;;

        for (int x = 0;x < StudentsQuantity;x++)
        {
            if (STUDENT[x].getname() != "")
            {

                cout << STUDENT[x].getname();
                cout << "\t\t";
                cout <<to_string(STUDENT[x].getmarks());
                cout << endl;
            }
           
        }
    }
    void mydatabase::UpdateData()
    {
        string name;
        int marks;
        bool status = false;
        cout << "Enter name of student that you want to update: ";
        cin >> name;
        cout << "Enter new marks: ";
        cin >> marks;
        for (int x = 0;x <StudentsQuantity;x++)
        {
            if (STUDENT[x].getname()==name)
            {
                status = true;
                STUDENT[x].setmarks(marks);
            }
        }
        if (status)
            cout << "Marks updated successfuly";
        else
            cout << "Student not found";
    }
    void mydatabase::WriteData()
    {
        File.close();
        ofstream file;
        file.open(filename);
        
        for (int x = 0;x < StudentsQuantity;x++)
        {
            if (STUDENT[x].getname() != "")
            {
                file << STUDENT[x].getname() << endl;
                file << STUDENT[x].getmarks() << endl;

            }
            }
        cout << "DATA SAVED INTO DATABASE SUCCESSFULLY";
    }
    void mydatabase::RemoveStudent()
    {
        string name;
        cout << "Enter name of student that you want to remove: ";
        cin >> name;
        bool status = false;
        for (int x = 0;x < StudentsQuantity;x++)
        {
            if (STUDENT[x].getname() == name)
            {
                status = true;
                STUDENT[x].setname("");
            }
        }
        if (status)
            cout << "Student removed successfuly";
        else
            cout << "Student not found";
    }
    void mydatabase::AddData()
    {
        cout << "Enter student name: ";
        string n;
        int m;
        cin >> n;
        cout << "Enter student marks: ";
        cin >> m;
        STUDENT[StudentsQuantity].setname(n);
        STUDENT[StudentsQuantity].setmarks(m);
        if(StudentsQuantity!=999)
            StudentsQuantity++;
        cout << "Student added successfuly";
    }
    void mydatabase::RemoveAllData()
    {
        for (int x = 0;x < StudentsQuantity;x++)
        {
            STUDENT[x].setname("");
        }
        cout << "All data has been deleted";
    }
    void mydatabase::ChangeDatabaseFile()
    {
        cout << "Enter new DB file 'newfile.txt' (if it does not exist, it will be created): ";
        cin >> filename;
        File.close();
        ReadData();

    }

    void mydatabase::menu()
    {
        ReadData();
        int option;
        do
        {
            cout << endl << endl;
            cout << "Selected DB file:" + filename << endl;
            cout << "You must have to save changes (option 5) after modifying data or before changing database";
            cout << endl << endl;
            cout << "Enter 1 to add STUDENT into DB \nEnter 2 to remove STUDENT from DB\n";
            cout << "Enter 3 to update STUDENT \nEnter 4 to print DB\n";
            cout << "Enter 5 to save any changes into DB \nEnter 6 to change DB file\n";
            cout << "Enter 7 to drop table from DB \n";
            cout << "Enter 8 to exit \n\n";
            cout << "Option: ";
            cin >> option;
            system("cls");
            cout << endl;
            if (option == 1)
            {
                AddData();
            }
            else if (option == 2)
            {
                RemoveStudent();
            }
            else if (option == 3)
            {
               UpdateData();
            }
            else if (option == 4)
            {
                PrintData();
            }
            else if (option == 5)
            {
                WriteData();
            }
            else if (option == 6)
            {
                ChangeDatabaseFile();
            }
            else if (option == 7)
            {
                RemoveAllData();
            }
        } while (option != 8);
    }

int main()
{
    mydatabase driver;

}
