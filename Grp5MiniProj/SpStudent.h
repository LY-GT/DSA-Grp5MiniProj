#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <list>

using namespace std;

/*Stores data of students in a object*/
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

/*Used to call functions regarding the whole vector/stack of students(objects)*/
class studentlist {
public:
	studentlist(string filepath);

	vector<student_class> students; //vector
	bool check_same(student_class, student_class);

	//VECTOR FUNCTIONS
	vector<student_class> find1stClub(studentlist, char, int);
	vector<student_class> replaceWins_vector(vector<student_class>, char);
	void remainding_vector(studentlist&, vector<student_class>);
	

	

	//Chose to public the functions cause I'm lazy to do 
	//work around on if they were private lol

	//LIST FUNCTIONS
	//list<student_class> find1stClub_list(studentlist, char);
	//list<student_class> replaceWins(list<student_class>, char);
	//list<student_class> remainding(studentlist, list<student_class>);

	void printInfo(student_class);//stack print, not in use.


};
