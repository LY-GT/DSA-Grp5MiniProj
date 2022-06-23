#include "SpStudent.h"
#include <iostream>
using namespace std;

//SpStudent functions
SpStudent::SpStudent(string studentinfomation)
{
	stringstream studentin(studentinfomation);
	studentin >> firstname;
	studentin >> lastname;
	studentin >> GPA;
}
string SpStudent::getfirstname()
{
	return firstname;
}
string SpStudent::getlastname()
{
	return lastname;
}
string SpStudent::getname()
{
	return firstname + " " + lastname;
}
double SpStudent::getGPA()
{
	return GPA;
}

//list functions
list::list(string filepath)
{
	ifstream studentpath(filepath);

	string contents;
	while (!studentpath.eof())
	{
		getline(studentpath, contents);
		
		SpStudent s(contents);
		students.push_back(s);
	}
	studentpath.close();

	
}