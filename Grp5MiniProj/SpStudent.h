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
	char choice[3];//I have not figured out how to deal with choices
	int win[3];//or wins yet, feel free to experiment
};

class list {
public:
	list(string filepath);

private://You can private this if you want to test if your pathing is working
	vector<SpStudent> students;

};