#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "SpStudent.h"
#include "vacancyfile.h"

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
	cout << student_class.getWinchoice3() << " " << endl;

}

//TO PRINT CONTENTS OF VACANCYFILE
void print(Vacancies Vacancies) {
	cout << Vacancies.getCCAName() << " ";
	cout << Vacancies.getCCAID() << " ";
	cout << Vacancies.getvacancies() << " " << endl;
}


int main() {

	//student_class student_class("John Joe 3.0 g");
	studentlist filelist("C:\\Users\\KalliasWolf\\Documents\\studentinfonew.txt");
	vacancieslist vacancyfile("C:\\Users\\KalliasWolf\\Documents\\Vacancy.txt");
	//change the above if you want to change ^^^


//*********************************
	// I made 2 versions to find the 1st choice, LIST and VECTOR
	// Both are valid. I don't know which is better. 
	// Pick the one that works :D

//======================================================
//  LIST VERSION OF FINDING 1ST CHOICE
	/*
	for (student_class s : filelist.find1stClub_list(filelist, 'g'))
		test(s);

	list<student_class> chesslist_1 = filelist.find1stClub_list(filelist, 'g');
	list<student_class> chess_list_wins = filelist.replaceWins(chesslist_1, 'g'); //NOT DONE
	//^^Can combine these 2 together tbh, but it will be messy :D^^

	//After making a list of 1st choice and 3 winning records people
	//It is time to update the master file, aka remove people in the list
	//we just made from the whole population list.


	list<student_class> remainder = filelist.remainding(filelist, chess_list_wins);
	//^^This is to find the remainding people with no given club^^ NOT DONE



	*/


//===========================================================
// 	VECTOR VERSION OF FINDING 1ST CHOICE

	//Prints those who have chess as 1st choice (VECTOR)
	for (student_class s : filelist.find1stClub(filelist, 'g',9))
		test(s);
	

	vector<student_class> chesslist_nowins = filelist.find1stClub(filelist, 'g',9);

	//cout << filelist.students.size() << endl;
	//cout << vacancyfile.ccavacancy.size() << endl;
	
	//vector<student_class> chesslist_wins = filelist.replaceWins_vector(chesslist_nowins, 'g');
	//vector<student_class> remainder = filelist.remainding_vector(filelist, chesslist_wins);

	//Printing Out CCA + ID + Vacancies
	cout << "Name of CCA " << "	" << "CCAID " << "	" << "Number of Vacancies " << endl;
	cout << "======================================================================" << endl;
	for (int i = 0; i < vacancyfile.ccavacancy.size(); i++) {
		Vacancies v = vacancyfile.ccavacancy.at(i);
		print(v);
	}

	//Assigning vacancies to variables
	int Dancingvacancies;
	int Tennisvacancies;
	int Gamingvacancies;
	int Runningvacancies;
	int swimmingvacancies;
	int chessvacancies; 

	for (int i = 0; i < vacancyfile.ccavacancy.size(); i++) {
		Vacancies v = vacancyfile.ccavacancy.at(i);
		if (v.getCCAID() == 'D') {
			Dancingvacancies = v.getvacancies();
		}
		if (v.getCCAID() == 'T') {
			Tennisvacancies = v.getvacancies();
		}
		if (v.getCCAID() == 'G') {
			Gamingvacancies = v.getvacancies();
		}
		if (v.getCCAID() == 'R') {
			Runningvacancies = v.getvacancies();
		}
		if (v.getCCAID() == 'S') {
			swimmingvacancies = v.getvacancies();
		}
		if (v.getCCAID() == 'C') {
			chessvacancies = v.getvacancies();
		}
	}








	

		
		//Prints the whole student list
		/*for (int i = 0; i < filelist.students.size(); i++)
		{
			student_class s = filelist.students.at(i);
			test(s);
		}*/
		
		


	return 0;


}