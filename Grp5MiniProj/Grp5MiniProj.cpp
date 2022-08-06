#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "SpStudent.h"
#include "vacancyfile.h"
#include <vector>
using namespace std;
//For round 2
char checker;
bool sortingfunctionGPA(student_class& s1, student_class& s2);
void printingfxn(vector<student_class> toprint);
void test(student_class student_class);
bool sortingfunctionwins(student_class& s1, student_class& s2)
{
	double s1wins = 0;
	double s2wins = 0;
	//Checking wins 
	if (s1.getChoice2() == checker)
		s1wins = s1.getWinchoice2();
	if (s1.getChoice3() == checker)
		s1wins = s1.getWinchoice3();
	if (s2.getChoice2() == checker)
		s2wins = s2.getWinchoice2();
	if (s2.getChoice3() == checker)
		s2wins = s2.getWinchoice3();
	if (s1wins < s2wins) {
		return false;
	}
	else if (s1wins = s2wins) {
		return sortingfunctionGPA(s1, s2);
	}
	else
		return true;
}

struct sortbyGPA
{
	bool operator () (student_class& A, student_class& B) {
		return (A.getGPA() > B.getGPA());
	}
}

bool round2endsort(student_class& s1, student_class& s2)
{
	double s1wins = 0;
	double s2wins = 0;
	//Checking wins 
	if (s1.getChoice1() == checker)
		s1wins = s1.getWinchoice1();
	if (s1.getChoice2() == checker)
		s1wins = s1.getWinchoice2();
	if (s1.getChoice3() == checker)
		s1wins = s1.getWinchoice3();
	if (s2.getChoice1() == checker)
		s2wins = s2.getWinchoice1();
	if (s2.getChoice2() == checker)
		s2wins = s2.getWinchoice2();
	if (s2.getChoice3() == checker)
		s2wins = s2.getWinchoice3();
	if (s1wins < s2wins) {
		return false;
	}
	else if (s1wins = s2wins) {
		return sortingfunctionGPA(s1, s2);
	}
	else
		return true;
}

bool sortingfunctionGPA(student_class& s1, student_class& s2) {
	if (s1.getGPA() < s2.getGPA())
		return false;
	else
		return true;
}

void printingfxn(vector<student_class> toprint){
	for (int i = 0; i < toprint.size(); i++)
	{
		student_class s = toprint.at(i);
		test(s);
	}
}
/*                                                                            */

struct sortbyCLUB_WINS
{
	sortbyCLUB_WINS(char club) { this->club = club; }
	bool operator () (student_class& A, student_class& B) {

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
		//reference: -https://stackoverflow.com/questions/4066576/passing-a-parameter-to-a-comparison-function
	}
	char club;

};

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
	studentlist filelist("C:\\Users\\USER\\Documents\\Student.txt");
	vacancieslist vacancyfile("C:\\Users\\USER\\Documents\\Vacancy.txt");

	//Assigning vacancies to variables
	int Dancingvacancies = 0;
	int Tennisvacancies = 0;
	int Gamingvacancies = 0;
	int Runningvacancies = 0;
	int Swimmingvacancies = 0;
	int Chessvacancies = 0;
	string DancingCCA;
	string TennisCCA;
	string GamingCCA;
	string RunningCCA;
	string SwimmingCCA;
	string ChessCCA;
	char dancingid;
	char tennisid;
	char gamingid;
	char runningid;
	char swimmingid;
	char chessid;
	string specialcca;

	for (int i = 0; i < vacancyfile.ccavacancy.size(); i++) {
		Vacancies v = vacancyfile.ccavacancy.at(i);
		if (v.getCCAID() == 'd') {
			Dancingvacancies = v.getvacancies();
			DancingCCA = v.getCCAName();
			dancingid = v.getCCAID();
		}
		if (v.getCCAID() == 't') {
			Tennisvacancies = v.getvacancies();
			TennisCCA = v.getCCAName();
			tennisid = v.getCCAID();
		}
		if (v.getCCAID() == 'g') {
			Gamingvacancies = v.getvacancies();
			GamingCCA = v.getCCAName();
			gamingid = v.getCCAID();
		}
		if (v.getCCAID() == 'r') {
			Runningvacancies = v.getvacancies();
			RunningCCA = v.getCCAName();
			runningid = v.getCCAID();
		}
		if (v.getCCAID() == 's') {
			Swimmingvacancies = v.getvacancies();
			SwimmingCCA = v.getCCAName();
			swimmingid = v.getCCAID();
		}
		if (v.getCCAID() == 'c') {
			Chessvacancies = v.getvacancies();
			ChessCCA = v.getCCAName();
			chessid = v.getCCAID();
		}
		if (v.getCCAID() == 'G') {
			specialcca = v.getCCAName();
		}
	}
	//cout << specialcca << endl;



	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS('d'));
	vector<student_class> dancinglist_nowins = filelist.find1stClub(filelist, 'd', Dancingvacancies);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS('t'));
	vector<student_class> tennislist_nowins = filelist.find1stClub(filelist, 't', Tennisvacancies);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS('g'));
	vector<student_class> gaminglist_nowins = filelist.find1stClub(filelist, 'g', Gamingvacancies);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS('r'));
	vector<student_class> runninglist_nowins = filelist.find1stClub(filelist, 'r', Runningvacancies);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS('s'));
	vector<student_class> swimminglist_nowins = filelist.find1stClub(filelist, 's', Swimmingvacancies);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS('c'));
	vector<student_class> chesslist_nowins = filelist.find1stClub(filelist, 'c', Chessvacancies);


	//###Printing Out CCA + ID + Vacancies###
	cout << "Name of CCA " << "	" << "CCAID " << "	" << "Number of Vacancies " << endl;
	//Print out contents of list
	for (int i = 0; i < vacancyfile.ccavacancy.size(); i++) {
		Vacancies v = vacancyfile.ccavacancy.at(i);
		print(v);
	}

	cout << "======================================================================" << endl;
	cout << "FULL LIST OF STUDENTS AND INFORMATION\n";

	//Prints the whole student list
	for (student_class s : filelist.students)
		test(s);


	cout << "======================================================================" << endl;
	cout << "LIST OF GAMING LIST PEOPLE\n";

	for (int i = 0; i < gaminglist_nowins.size(); i++) {
		student_class s = gaminglist_nowins.at(i);
		test(s);
	}

	cout << "======================================================================" << endl;
	cout << "LIST OF DANCING LIST PEOPLE\n";

	for (int i = 0; i < dancinglist_nowins.size(); i++) {
		student_class s = dancinglist_nowins.at(i);
		test(s);
	}

	cout << "======================================================================" << endl;
	cout << "LIST OF CHESS LIST PEOPLE\n";

	for (int i = 0; i < chesslist_nowins.size(); i++) {
		student_class s = chesslist_nowins.at(i);
		test(s);
	}

	cout << "======================================================================" << endl;
	cout << "LIST OF RUNNING LIST PEOPLE\n";

	for (int i = 0; i < runninglist_nowins.size(); i++) {
		student_class s = runninglist_nowins.at(i);
		test(s);
	}

	cout << "======================================================================" << endl;
	cout << "LIST OF SWIMMING LIST PEOPLE\n";

	for (int i = 0; i < swimminglist_nowins.size(); i++) {
		student_class s = swimminglist_nowins.at(i);
		test(s);
	}

	cout << "======================================================================" << endl;
	cout << "LIST OF TENIS LIST PEOPLE\n";

	for (int i = 0; i < tennislist_nowins.size(); i++) {
		student_class s = tennislist_nowins.at(i);
		test(s);
	}


	//Round 2
	vector<student_class> specialvector;
	vector<student_class> checkervector;
	int checkvac;
	int count = 0;
	//Create a function to assign the id to search 
	//Checker is global
	if (specialcca == DancingCCA) {
		checker = dancingid;
		checkervector = dancinglist_nowins;
		checkvac = Dancingvacancies;
	}
	if (specialcca == TennisCCA) {
		checkervector = tennislist_nowins;
		checker = tennisid;
		checkvac = Tennisvacancies;
	}
	if (specialcca == GamingCCA) {
		checkervector = gaminglist_nowins;
		checker = gamingid;
		checkvac = Gamingvacancies;
	}
	if (specialcca == RunningCCA) {
		checkervector = runninglist_nowins;
		checker = runningid;
		checkvac = Runningvacancies;
	}
	if (specialcca == SwimmingCCA) {
		checkervector = swimminglist_nowins;
		checker = swimmingid;
		checkvac = Swimmingvacancies;
	}
	if (specialcca == ChessCCA) {
		checkervector = chesslist_nowins;
		checker = chessid;
		checkvac = Chessvacancies;
	}
	cout << checkvac;
	//Checks for no. of 'Special' students in the vector holding the cca students
	cout << "==============================================" << endl;
	for (int i = 0; i < checkervector.size(); i++) {
		student_class s = checkervector.at(i);
		//test(s);
		if (s.getWinchoice1() >= '1') {
			count++;
		}
	}

	cout << "No. of specialstudents " << count << endl;
	//Checking chesscca for special students (students with wins in the special sport)
	//if vectorsize > vacacny
	if (count < 3) {
		for (int i = 0; i < gaminglist_nowins.size(); i++) {
			student_class s = gaminglist_nowins.at(i);
			if (specialcca == GamingCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < chesslist_nowins.size(); i++) {
			student_class s = chesslist_nowins.at(i);
			if (specialcca == ChessCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < tennislist_nowins.size(); i++) {
			student_class s = tennislist_nowins.at(i);
			if (specialcca == TennisCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < dancinglist_nowins.size(); i++) {
			student_class s = dancinglist_nowins.at(i);
			if (specialcca == DancingCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < runninglist_nowins.size(); i++) {
			student_class s = runninglist_nowins.at(i);
			if (specialcca == RunningCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < swimminglist_nowins.size(); i++) {
			student_class s = swimminglist_nowins.at(i);
			if (specialcca == SwimmingCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
	}

	cout << "Potential Stolen Candidates " << endl;
	for (int i = 0; i < specialvector.size(); i++)
	{
		student_class s = specialvector.at(i);
		test(s);
	}


	cout << endl;

	cout << "=====================================" << endl;
	//Sorts by no.wins
	while (bool ender = true) {
		if (specialvector.size() == 0) {
			cout << "There are no special students..." << endl;
			break;
		}
		sort(specialvector.begin(), specialvector.end(), sortingfunctionwins);
		cout << "Sorted by Wins " << endl;
		for (int i = 0; i < specialvector.size(); i++)
		{
			student_class s = specialvector.at(i);
			test(s);
		}
		//Adds students from specialvector into special cca
		//no. to add 
		int adding = 3 - count;
		int potentialcandidates = specialvector.size();
		//cout << potentialcandidates;
		if (checker == gamingid) {
			for (int i = 0; i < specialvector.size(); i++) {
				gaminglist_nowins.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			sort(gaminglist_nowins.begin(), gaminglist_nowins.end(), round2endsort);
			if (gaminglist_nowins.size() > Gamingvacancies)
				gaminglist_nowins.pop_back();
			checkervector = gaminglist_nowins;
			break;
		}
		if (checker == chessid) {
			for (int i = 0; i < specialvector.size(); i++) {
				chesslist_nowins.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			sort(chesslist_nowins.begin(), chesslist_nowins.end(), round2endsort);
			if (chesslist_nowins.size() > Chessvacancies)
				chesslist_nowins.pop_back();
			checkervector = chesslist_nowins;
			break;
		}
		if (checker == tennisid) {
			for (int i = 0; i < specialvector.size(); i++) {
				tennislist_nowins.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			sort(tennislist_nowins.begin(), tennislist_nowins.end(), round2endsort);
			if (tennislist_nowins.size() > Tennisvacancies)
				tennislist_nowins.pop_back();
			checkervector = tennislist_nowins;
			break;
		}
		if (checker == dancingid) {
			for (int i = 0; i < specialvector.size(); i++) {
				dancinglist_nowins.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			sort(dancinglist_nowins.begin(), dancinglist_nowins.end(), round2endsort);
			if (dancinglist_nowins.size() > Dancingvacancies)
				dancinglist_nowins.pop_back();
			checkervector = dancinglist_nowins;
			break;
		}

		if (checker == runningid) {
			for (int i = 0; i < specialvector.size(); i++) {
				runninglist_nowins.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			sort(runninglist_nowins.begin(), runninglist_nowins.end(), round2endsort);
			if (runninglist_nowins.size() > Runningvacancies)
				runninglist_nowins.pop_back();
			checkervector = runninglist_nowins;
			break;
		}

		if (checker == swimmingid) {
			for (int i = 0; i < specialvector.size(); i++) {
				swimminglist_nowins.push_back(specialvector[i]);
				if (i  +1 >= adding) {
					break;
				}
			}
			sort(swimminglist_nowins.begin(), swimminglist_nowins.end(), round2endsort);
			if (swimminglist_nowins.size() > Swimmingvacancies)
				swimminglist_nowins.pop_back();
			checkervector = swimminglist_nowins;
			break;
		}
	}

	
	
	

	cout << "=====================================" << endl;
	printingfxn(checkervector);
	/*for (int i = 0; i < swimminglist_nowins.size(); i++)
	{
		student_class s = swimminglist_nowins.at(i);
		test(s);
	}*/
	//End of round 2





	cout << "======================================================================" << endl;
	cout << "Number of students: " << filelist.students.size() << endl;
	cout << "Number of cca vacancy? idk what this is: " << vacancyfile.ccavacancy.size() << endl;

	cout << "======================================================================" << endl;
	cout << "Remaining students who have no given sport\n";



	filelist.remainding_vector(filelist, gaminglist_nowins);
	filelist.remainding_vector(filelist, chesslist_nowins);
	filelist.remainding_vector(filelist, dancinglist_nowins);
	filelist.remainding_vector(filelist, runninglist_nowins);
	filelist.remainding_vector(filelist, swimminglist_nowins);
	filelist.remainding_vector(filelist, tennislist_nowins);

	for (student_class s : filelist.students)
		test(s);

	//Start of round 5
	sort(filelist.students.begin(), filelist.students.end(), sortbyGPA());

	srand(time(0)); //This is to set a random seed for the RNG (random number generator)

	do {
		int rng = rand() % 6; //randomly sets a number from 0 to 5
		switch (rng)
		{
		case 0: //case when rolled for Dancing (number = 0)
			//Code for assigning student into dancing (Not yet implimented)
			if (Dancingvacancies > 0)
			{
				dancinglist.push_back(studentlist.student.back());
				cout << "Sent to Dancing" << endl;
				studentlist.student.pop_back();
				Dancingvacancies -= 1;
				break;
			}
			else
			{
				cout << "No vacancies in Dancing" << endl;
				i--;
				break;
			}

		case 1: //case when rolled for Tennis (number = 1)
			//Code for assigning student into tennis (Not yet implimented)
			if (Tennisvacancies > 0)
			{
				tennislist.push_back(studentlist.student.back());
				cout << "Sent to Tennis" << endl;
				studentlist.student.pop_back();
				Tennisvacancies -= 1;
				break;
			}
			else
			{
				cout << "No vacancies in Tennis" << endl;
				i--;
				break;
			}

		case 2: //case when rolled for Gaming (number = 2)
			//Code for assigning student into gaming (Not yet implimented)
			if (Gamingvacancies > 0)
			{
				gaminglist.push_back(studentlist.student.back());
				cout << "Sent to Gaming" << endl;
				studentlist.student.pop_back();
				Gamingvacancies -= 1;
				break;
			}
			else
			{
				cout << "No vacancies in Gaming" << endl;
				i--;
				break;
			}

		case 3: //case when rolled for Running (number = 3)
			//Code for assigning student into running (Not yet implimented)
			if (Runningvacancies > 0)
			{
				runninglist.push_back(studentlist.student.back());
				cout << "Sent to Running" << endl;
				studentlist.student.pop_back();
				Runningvacancies -= 1;
				break;
			}
			else
			{
				cout << "No vacancies in Running" << endl;
				i--;
				break;
			}

		case 4: //case when rolled for Swimming (number = 4)
			//Code for assigning student into swimming (Not yet implimented)
			if (Swimmingvacancies > 0)
			{
				swimminglist.push_back(studentlist.student.back());
				cout << "Sent to Swimming" << endl;
				studentlist.student.pop_back();
				Swimmingvacancies -= 1;
				break;
			}
			else
			{
				cout << "No vacancies in Swimming" << endl;
				i--;
				break;
			}

		case 5: //case when rolled for Chess (number =5)
			//Code for assigning student into chess (Not yet implimented)
			if (Chessvacancies > 0)
			{
				chesslist.push_back(studentlist.student.back());
				studentlist.student.pop_back();
				cout << "Sent to Chess" << endl;
				Chessvacancies -= 1;
				break;
			}
			else
			{
				cout << "No vacancies in Chess" << endl;
				i--;
				break;
			}

		default: //default case when RNG doesnt go right.. Should not be the case
			cout << "Error in the random number genrator.. Please check Round 5's code" << endl;
			break;

		}while (studentlist.student.size() != 0)
	}


	return 0;

	
}