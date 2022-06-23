// Grp5MiniProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "SpStudent.h"
using namespace std;

/*void studentfileread()
{
    vector<char> filepath;
    ifstream studentpath(filepath);

    string contents;
    while (!student.eof())
    {
        

        SpStudent s(contents);
        students.push_back(s);
    }
    studentpath.close();
}*/

void test(SpStudent student)
{
    cout << "First name: " << student.getfirstname() << endl;
    cout << "Last name: " << student.getlastname() << endl;
    cout << "GPA: " << student.getGPA() << endl;
    cout << "Full name: " << student.getname() << endl;
    cout << endl;
}

int main()
{
    list list("c:\\Users\\USER\\Documents\\studentinfo.txt");
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
