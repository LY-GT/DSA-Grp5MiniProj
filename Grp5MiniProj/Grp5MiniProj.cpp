#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "SpStudent.h"

using namespace std;


//TO PRINT OUTPUT
void test(student_class student_class) {

	cout << student_class.getFirst_name() << " ";
	cout << student_class.getLast_name() << " ";
	cout << student_class.getGPA() << " ";
	cout << student_class.getChoice1() << " ";
	cout << student_class.getChoice2() << " ";
	cout << student_class.getChoice3() << " ";
	cout << student_class.getWinchoice1() << " ";
	cout << student_class.getWinchoice2() << " ";
	cout << student_class.getWinchoice3() << " ";

}

int main() {

	//student_class student_class("John Joe 3.0 g");
	studentlist filelist("C:\\Users\\jeann\\Documents\\studentinfo.txt");
	//change the above if you want to change ^^^

//*********************************
	// I made 2 versions to find the 1st choice, LIST and STACK+VECTOR
	// LIST is better I feel cause got iterator compared to stack.
	// Please comment the one you are not using so you don't confuse yourself
	// Feel free to edit anything, original code will still be with me

//======================================================
//  LIST VERSION OF FINDING 1ST CHOICE
	for (student_class s : filelist.find1stClub_list(filelist, 'g'))
		test(s);

	list<student_class> x = filelist.find1stClub_list(filelist, 'g');
	//list<student_class> chess_list=filelist.replaceWins(x,'g'); //NOT DONE
	//^^Can combine these 2 together tbh, but it will be messy :D^^

	//After making a list of 1st choice and 3 winning records people
	//It is time to update the master file, aka remove people in the list
	//we just made from the whole population list.


	//list<student_class> remainder = filelist.remainding(filelist, chess_list);
	//^^This is to find the remainding people with no given club^^ NOT DONE






//===========================================================
// 	VECTOR + STACK VERSION OF FINDING 1ST CHOICE

	//Prints those who have chess as 1st choice (VECTOR)
	for (student_class s : filelist.find1stClub(filelist, 'g'))
		test(s);

	//1. Makes a vector of people with chess 
	//2. Removes extra people, turns vector into stack
	stack<student_class> v = filelist.sorter(filelist.find1stClub(filelist, 'g'), 2);

	//To check the stack is working normally.
	while (!v.empty())
	{
		student_class s = v.top();
		filelist.printInfo(s);
		v.pop();
	}

	///////////////////////////////////////////////////////////

		/*
		//Prints the whole student list
		for (int i = 0; i < filelist.students.size(); i++)
		{
			student_class s = filelist.students.at(i);
			test(s);
		}
		*/
		///////////////////////////////////////////////////////


	return 0;


}