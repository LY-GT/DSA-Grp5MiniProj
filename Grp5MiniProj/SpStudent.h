#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <list>

using namespace std;


class student_class {
public:
	student_class(string studentinfomation);

	string getFirst_name();
	string getLast_name();
	double getGPA();
	char getChoice1();
	char getChoice2();
	char getChoice3();
	char getWinchoice1();
	char getWinchoice2();
	char getWinchoice3();

	


private:
	string first_name;
	string last_name;
	double GPA;
	char choice1;
	char choice2;
	char choice3;
	char winchoice1;
	char winchoice2;
	char winchoice3;


};


class studentlist {
public:
	studentlist(string filepath);

	vector<student_class> students; 
	bool check_same(student_class, student_class);
	void print(student_class);

	
	vector<student_class> find1stClub(studentlist, char, int);
	vector<student_class> find2ndClub(studentlist, char, int);
	vector<student_class> find3rdClub(studentlist, char, int);
	void remainding_vector(studentlist&, vector<student_class>);
	void remainding_vector2(studentlist&, vector<student_class>);
	void remainding_vector3(vector<student_class>&, vector<student_class>&);

	
};
