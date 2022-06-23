#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//header file for class SpStudent

class SpStudent {
public:
	//SpStudent();
	SpStudent(string studentinfomation);
	string getfirstname();
	string getlastname();
	string getname();
	double getGPA();


private:
	string firstname;
	string lastname;
	double GPA;
	char choice[3];
	int win[3];
};

class list {
public:
	list(string filepath);

//private:
	vector<SpStudent> students;

};