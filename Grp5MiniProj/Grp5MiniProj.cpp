// Grp5MiniProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "SpStudent.h"
using namespace std;

/*void fileinput()
{
    char filename[100];
    char defaultpath[100]{ d,e,f,a,u,l,t };
    cout << "Enter a file path, if you want to use the default path, type default" << endl;
    cout << "File name: ";
    cin.getline(filename, 99);
    if filename = defaultpath
    {
        list list("c:\\Users\\USER\\Documents\\studentinfo.txt");
    }
    else
    {
        list list(filename);
    }
    //Ive not gotten this to work yet, if you want to attempt fixing this go ahead, I cant figure out the issue yet
}*/

void test(SpStudent student)
{
    cout << "First name: " << student.getfirstname() << endl;
    cout << "Last name: " << student.getlastname() << endl;
    cout << "GPA: " << student.getGPA() << endl;
    cout << "Full name: " << student.getname() << endl;
    cout << endl;
    //this is a test for file reading, use it if you want to, 
    //but look in SpStudent.h first to // the private part of the list class
}

int main()
{
    list list("C:\\Users\\USER\\Documents\\studentinfo.txt");
    //when pathing to your file, use double \ for every path. Its a thing with fstream idk.
    // so if your file is in C:\Users\Name\Documents, type it as C:\\Users\\Name\\Documents\\(filename).txt
    //fileinput();
    for (SpStudent s : list.students)
        test(s);

    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
