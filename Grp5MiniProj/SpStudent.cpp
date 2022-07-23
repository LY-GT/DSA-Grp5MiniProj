#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <list>
#include "Spstudent.h"

using namespace std;

student_class::student_class(string studentinformation)
{
	stringstream studentin(studentinformation);
	studentin >> first_name;
	studentin >> last_name;
	studentin >> GPA;
	studentin >> choice1;
	studentin >> choice2;
	studentin >> choice3;
	studentin >> winchoice1;
	studentin >> winchoice2;
	studentin >> winchoice3;

}

string student_class::getFirst_name()
{
	return first_name;
}

string student_class::getLast_name()
{
	return last_name;
}

char student_class::getChoice1()
{
	return choice1;

}

char student_class::getChoice2()
{
	return choice2;

}

char student_class::getChoice3()
{
	return choice3;

}

char student_class::getWinchoice1()
{
	return winchoice1;
}

char student_class::getWinchoice2()
{
	return winchoice2;
}

char student_class::getWinchoice3()
{
	return winchoice3;
}

double student_class::getGPA()
{
	return GPA;
}

//========================================================================
//List version of finding 1st choice and making it the correct size.

list<student_class> studentlist::find1stClub_list(studentlist listStudent, char club) {

	list<student_class> x;

	for (student_class s : listStudent.students)
	{
		if (s.getChoice1() == club)
		{
			x.push_back(s);

		}
	}
	if (x.size() != 2) {
		x.pop_back();
	}

	return x;

}
//*************************ROUND 2?**********************************
//You can redo this tbh lol

list<student_class> studentlist::replaceWins(list<student_class> x, char club)
{
	//check if current list have less than 3 students with winning records
	//How do define winning record? with only 0 and 1 (No or Yes)
	//or count how many competitions they have won? (Number)
	//The latter will be more difficult.
	// 
	//Check students with winning and replace(or not)/slot in(if got space)



}

list<student_class> studentlist::remainding(studentlist studentlist,
	list<student_class> firstPickandWins)
{
	list<student_class> returning;
	list<student_class>::iterator it;
	it = firstPickandWins.begin();
	for (int i = 0; i < studentlist.students.size(); i++, it++)
	{
		cout << "idk";
	}
	//idk somehow just get the remaining students with no spots left.

	return returning;

}

//==================================================================================
// VECTOR + STACK VERSION OF finding 1st choice and resizing it
// Put everyone who has (insert club here) as 1st choice
//I don't know how to make it stop counting w/ vector... had to use stack
vector<student_class> studentlist::find1stClub(studentlist list, char club) {

	vector<student_class> x;

	for (student_class s : list.students)
	{
		if (s.getChoice1() == club)
		{
			x.push_back(s);

		}
	}

	return x;

}

//Removes the extra people and converts vector into stack
//Why stack?
//Since it is sorted by GPA, the top people are people with lowest GPA
//Hence if they have to be replaced by winning records people, lowest GPA will be
//replaced, however when stack is made, order is (top)LOWEST to HIGHEST(bottom)
stack<student_class> studentlist::sorter(vector<student_class> find1stChess, int count) {
	stack<student_class> x;

	for (int i = 0; i != count; i++)
	{
		x.push(find1stChess.at(i));
	}

	return x;

}
//=================================================================================








//===============================================================
//READING OF FILE
studentlist::studentlist(string filepath)
{
	ifstream studentpath(filepath);

	string contents;

	while (!studentpath.eof())
	{
		getline(studentpath, contents);

		student_class s(contents);
		students.push_back(s); // push into vector

	}
	studentpath.close();

	//sort by GPA
	sort(students.begin(), students.end(), [](student_class& s1, student_class& s2)
	{
		return s1.getGPA() > s2.getGPA();
	});

}

//Used to print classes or print the class in stacks.
void studentlist::printInfo(student_class s) {

	cout << s.getFirst_name() << " " << s.getLast_name() << " "
		<< s.getGPA() << " " << s.getChoice1();
	return;

}