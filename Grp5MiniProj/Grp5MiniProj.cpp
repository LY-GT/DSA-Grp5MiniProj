#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "SpStudent.h"
#include "vacancyfile.h"
#include <vector>
char checker;
using namespace std;
bool sortingfunctionGPA(student_class& s1, student_class& s2);


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

bool sortingfunctionGPA(student_class& s1, student_class& s2) {
	if (s1.getGPA() < s2.getGPA())
		return false;
	else
		return true;
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

//TO PRINT CONTENTS OF VACANCYFILE
void print(Vacancies Vacancies) {
	cout << Vacancies.getCCAName() << " ";
	cout << Vacancies.getCCAID() << " ";
	cout << Vacancies.getvacancies() << " " << endl;
}


int main() {

	//student_class student_class("John Joe 3.0 g");
	studentlist filelist("C:\\Users\\KalliasWolf\\Documents\\Student.txt");
	vacancieslist vacancyfile("C:\\Users\\KalliasWolf\\Documents\\Vacancy.txt");


	//Assigning vacancies to variables
	int Dancingvacancies =0;
	int Tennisvacancies=0;
	int Gamingvacancies=0;
	int Runningvacancies=0;
	int swimmingvacancies=0;
	int chessvacancies=0;
	string specialcca;
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


	for (int i = 0; i < vacancyfile.ccavacancy.size(); i++) {
		Vacancies v = vacancyfile.ccavacancy.at(i);
		if (v.getCCAID() == 'd') {
			Dancingvacancies = v.getvacancies();
			DancingCCA = v.getCCAName();
			dancingid = v.getCCAID();
		}
		if (v.getCCAID() == 't') {
			Tennisvacancies = v.getvacancies();
			TennisCCA =v.getCCAName();
			tennisid = v.getCCAID();
		}
		if (v.getCCAID() == 'g') {
			Gamingvacancies = v.getvacancies();
			GamingCCA =v.getCCAName();
			gamingid = v.getCCAID();
		}
		if (v.getCCAID() == 'r') {
			Runningvacancies = v.getvacancies();
			RunningCCA = v.getCCAName();
			runningid = v.getCCAID();
		}
		if (v.getCCAID() == 's') {
			swimmingvacancies = v.getvacancies();
			SwimmingCCA = v.getCCAName();
			swimmingid = v.getCCAID();
		}
		if (v.getCCAID() == 'c') {
			chessvacancies = v.getvacancies();
			ChessCCA = v.getCCAName();
			chessid = v.getCCAID();
		}
		if (v.getCCAID() == 'G') {
			specialcca = v.getCCAName();
		}
	}
	

	vector<student_class> gaminglist_nowins = filelist.find1stClub(filelist, 'g', Gamingvacancies);
	vector<student_class> chesslist_nowins = filelist.find1stClub(filelist, 'c', chessvacancies);
	vector<student_class> tennislist_nowins = filelist.find1stClub(filelist, 't', Tennisvacancies);
	vector<student_class> dancinglist_nowins = filelist.find1stClub(filelist, 'd', Dancingvacancies);
	vector<student_class> runninglist_nowins = filelist.find1stClub(filelist, 'r', Runningvacancies);
	vector<student_class> swimminglist_nowins = filelist.find1stClub(filelist, 's', swimmingvacancies);

	//Start of ROUND 2
	vector<student_class> specialvector;
	vector<student_class> checkervector;
	int count = 0;
	//Create a function to assign the id to search 
	//Checker is global
	if (specialcca == DancingCCA) {
		checker = dancingid;
		checkervector = dancinglist_nowins;
	}
	if (specialcca == TennisCCA) {
		checkervector = tennislist_nowins;
		checker = tennisid;
	}
	if (specialcca == GamingCCA) {
		checkervector = gaminglist_nowins;
		checker = gamingid;
	}
	if (specialcca == RunningCCA) {
		checkervector = runninglist_nowins;
		checker = runningid;
	}
	if (specialcca == SwimmingCCA) {
		checkervector = swimminglist_nowins;
		checker = swimmingid;
	}
	if (specialcca == ChessCCA) {
		checkervector = chesslist_nowins;
		checker = chessid;
	}

	

	//Checks for no. of 'Special' students in the vector holding the cca students
	for (int i = 0; i < checkervector.size(); i++) {
		student_class s = checkervector.at(i);
		test(s);
		if (s.getWinchoice1() >= 1 ) {
			count++;
		}
	}



	cout << "No. of specialstudents " << count << endl;
	//Checking chesscca for special students (students with wins in the special sport)
	//if vectorsize > vacacny
	if (count < 3) {
		for (int i = 0; i < gaminglist_nowins.size(); i++) {
			student_class s = gaminglist_nowins.at(i);
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < chesslist_nowins.size(); i++) {
			student_class s = chesslist_nowins.at(i);
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < tennislist_nowins.size(); i++) {
			student_class s = tennislist_nowins.at(i);
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < dancinglist_nowins.size(); i++) {
			student_class s = dancinglist_nowins.at(i);
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < runninglist_nowins.size(); i++) {
			student_class s = runninglist_nowins.at(i);
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < swimminglist_nowins.size(); i++) {
			student_class s = swimminglist_nowins.at(i);
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
			checkervector = runninglist_nowins;
			break;
		}
		if (checker == swimmingid) {
			for (int i = 0; i < specialvector.size(); i++) {
				swimminglist_nowins.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			checkervector = swimminglist_nowins;
			break;
		}
	}


	cout << "=====================================" << endl;
	
	for (int i = 0; i < checkervector.size(); i++)
	{
		student_class s = checkervector.at(i);
		test(s);
	}
	//End of round 2

	return 0;


}