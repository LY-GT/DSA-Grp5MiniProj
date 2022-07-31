#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "SpStudent.h"
#include "vacancyfile.h"

using namespace std;


bool sortbyGPA(student_class& A, student_class& B) {

	char club = 'g'; //sort does not allow carry value.

	if (A.getChoice1() == club && B.getChoice1() == club)
	{
		return (A.getWinchoice1() > B.getWinchoice1());
	}
	else if (A.getChoice1() == club && B.getChoice1() == club)
	{
		return (A.getGPA() > B.getGPA());
	}
	else if (A.getChoice1() == club)
	{
		return true;
	}
	else
	{
		return false;
	}

}

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

void print(Vacancies v) {

	cout << v.getCCAName() << " ";
	cout << v.getCCAID() << " ";
	cout << v.getvacancies() << endl;

}

int main() {

	//student_class student_class("John Joe 3.0 g");
	studentlist filelist("C:\\Users\\jeann\\Documents\\studentinfo.txt");
	vacancieslist vacancyfile("C:\\Users\\jeann\\Documents\\Vacancy.txt");

	//Assigning vacancies to variables
	int Dancingvacancies;
	int Tennisvacancies;
	int Gamingvacancies;
	int Runningvacancies;
	int Swimmingvacancies;
	int chessvacancies;

	string specialcca;

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
			Swimmingvacancies = v.getvacancies();
		}
		if (v.getCCAID() == 'C') {
			chessvacancies = v.getvacancies();
		}
		if (v.getCCAID() == 'G') {
			specialcca = v.getCCAName();
		}
	}
	//cout << specialcca << endl;


	//Print out contents of list
	for (int i = 0; i < vacancyfile.ccavacancy.size(); i++) {
		Vacancies v = vacancyfile.ccavacancy.at(i);
		print(v);
	}

	vector<student_class> dancinglist_nowins = filelist.find1stClub(filelist, 'd', Dancingvacancies);
	vector<student_class> tennislist_nowins = filelist.find1stClub(filelist, 't', Tennisvacancies);
	vector<student_class> gaminglist_nowins = filelist.find1stClub(filelist, 'g', Gamingvacancies);
	vector<student_class> runninglist_nowins = filelist.find1stClub(filelist, 'r', Runningvacancies);
	vector<student_class> swimminglist_nowins = filelist.find1stClub(filelist, 's', Swimmingvacancies);
	vector<student_class> chesslist_nowins = filelist.find1stClub(filelist, 'c', chessvacancies);



	//###Printing Out CCA + ID + Vacancies###
	cout << "Name of CCA " << "	" << "CCAID " << "	" << "Number of Vacancies " << endl;
	cout << "======================================================================" << endl;

	//Prints the whole student list
	for (student_class s : filelist.students)
		test(s);
	

	cout << "======================================================================" << endl;
	

	for (int i = 0; i < gaminglist_nowins.size(); i++) {
		student_class s = gaminglist_nowins.at(i);
		test(s);
	}




	cout << "======================================================================" << endl;
	cout << filelist.students.size() << endl;
	cout << vacancyfile.ccavacancy.size() << endl;

	cout << "======================================================================" << endl;

	
	filelist.remainding_vector(filelist, gaminglist_nowins);
	for (student_class s : filelist.students)
		test(s);
	



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
	list<student_class> chess_list_wins=filelist.replaceWins(chesslist_1,'g'); //NOT DONE
	//^^Can combine these 2 together tbh, but it will be messy :D^^

	//After making a list of 1st choice and 3 winning records people
	//It is time to update the master file, aka remove people in the list
	//we just made from the whole population list.


	list<student_class> remainder = filelist.remainding(filelist, chess_list_wins);
	//^^This is to find the remainding people with no given club^^ NOT DONE





//===========================================================
// 	VECTOR VERSION OF FINDING 1ST CHOICE(Jeffs code)

	//Prints those who have chess as 1st choice (VECTOR)
	//for (student_class s : filelist.find1stClub(filelist, 'g',Gamingvacancies))
		//test(s);


	vector<student_class> gaminglist_nowins = filelist.find1stClub(filelist, 'g', Gamingvacancies);

	for (int i = 0; i < gaminglist_nowins.size(); i++) {
		student_class s = gaminglist_nowins.at(i);
		test(s);
	}

	//cout << filelist.students.size() << endl;
	//cout << vacancyfile.ccavacancy.size() << endl;

	//vector<student_class> chesslist_wins = filelist.replaceWins_vector(chesslist_nowins, 'g');
	//vector<student_class> remainder = filelist.remainding_vector(filelist, chesslist_wins);

	//Printing Out CCA + ID + Vacancies
	//cout << "Name of CCA " << "	" << "CCAID " << "	" << "Number of Vacancies " << endl;
	//cout << "======================================================================" << endl;



		//Prints the whole student list
		/*for (int i = 0; i < filelist.students.size(); i++)
		{
			student_class s = filelist.students.at(i);
			test(s);
		}*/







	/*//===========================================================
	// 	VECTOR VERSION OF FINDING 1ST CHOICE(Jeanna's code)
		//Prints those who have chess as 1st choice (VECTOR)

		//SORT BY G CLUB, WIN RECORD THEN GPA.
		sort(filelist.students.begin(), filelist.students.end(), sortbyGPA);

		cout << "Sorted by g club, win choice then GPA\n";

		for (int i = 0; i < filelist.students.size() - 1; i++)
		{
			student_class s = filelist.students.at(i);
			test(s);
		}
		cout << "\n====================================\n\nOnly 2 vacancy\n";

		for (student_class s : filelist.find1stClub(filelist, 'g'))
			test(s);


		vector<student_class> chesslist_nowins = filelist.find1stClub(filelist, 'g');
		//vector<student_class> chesslist_wins = filelist.replaceWins_vector(chesslist_nowins, 'g');
		//vector<student_class> remainder = filelist.remainding_vector(filelist, chesslist_wins);






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