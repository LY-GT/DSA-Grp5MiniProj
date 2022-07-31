#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
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

int main() {

	//student_class student_class("John Joe 3.0 g");
	studentlist filelist("C:\\Users\\jeann\\Documents\\studentinfo.txt");
	vacancieslist vacancyfile("C:\\Users\\KalliasWolf\\Documents\\Vacancy.txt");


	//Assigning vacancies to variables
	int Dancingvacancies;
	int Tennisvacancies;
	int Gamingvacancies;
	int Runningvacancies;
	int Swimmingvacancies;
	int Chessvacancies;
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
			swimmingvacancies = v.getvacancies();
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
	/*for (int i = 0; i < vacancyfile.ccavacancy.size(); i++) {
		Vacancies v = vacancyfile.ccavacancy.at(i);
		print(v);
	}*/




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

*/



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




	//return 0;


	/* //===========================================================
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


	//return 0; 
	


	//=========================================================
	//round 5 (Final round)


	srand(time(0)); //This is to set a random seed for the RNG (random number generator)

	int rng = rand() % 6; //randomly sets a number from 0 to 5
	switch (rng)
	{
	case 0: //case when rolled for Dancing (number = 0)
		//Code for assigning student into dancing (Not yet implimented)
		Dancingvacancies -= 1;
		break;

	case 1: //case when rolled for Tennis (number = 1)
		//Code for assigning student into tennis (Not yet implimented)
		Tennisvacancies -= 1;
		break;

	case 2: //case when rolled for Gaming (number = 2)
		//Code for assigning student into gaming (Not yet implimented)
		Gamingvacancies -= 1;
		break;

	case 3: //case when rolled for Running (number = 3)
		//Code for assigning student into running (Not yet implimented)
		Runningvacancies -= 1;
		break;

	case 4: //case when rolled for Swimming (number = 4)
		//Code for assigning student into swimming (Not yet implimented)
		Swimmingvacancies -= 1;
		break;

	case 5: //case when rolled for Chess (number =5)
		//Code for assigning student into chess (Not yet implimented)
		Chessvacancies -= 1;
		break;

	default: //default case when RNG doesnt go right.. Should not be the case
		cout << "Error in the random number genrator.. Please check Round 5's code" << endl;
		break;

	}

}