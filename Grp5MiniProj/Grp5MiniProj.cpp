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
	{
		return false;
	}
	else 
	{
		return true;
	}
}

void printingfxn(vector<student_class> toprint){
	for (int i = 0; i < toprint.size(); i++)
	{
		student_class s = toprint.at(i);
		test(s);
	}
}
/*                                                                            */
struct sortbyGPA
{
	bool operator () (student_class& A, student_class& B) {
		return (A.getGPA() > B.getGPA());
	}
};

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
	string username;
	int option;
	string studentpath;
	string vacancypath;
	cout << "Choose if you want to type in your username (option 1) or to type in the pathfiles (option 2): ";
	cin >> option;
	while (option < 1 || option > 2)
	{
		cout << "Invalid option\n";
		cout << "Please choose option 1 or 2: ";
		cin >> option;

	}
	switch (option)
	{
	case 1:
		cout << "This method requires you to have Student.txt and Vacancy.txt to be in Documents." << endl;
		cout << "Please type in your username that is used on this computer: ";
		cin.ignore();
		getline(cin, username);
		studentpath = "C:\\Users\\" + username + "\\Documents\\Student.txt";
		vacancypath = "C:\\Users\\" + username + "\\Documents\\Vacancy.txt";


		break;
	case 2:
		cout << "Please type the path file for student info: ";
		cin.ignore();
		getline(cin, studentpath);
		cout << "Please type the path file for vacancypath: ";
		getline(cin, vacancypath);
		break;
	}

	studentlist filelist(studentpath);
	vacancieslist vacancyfile(vacancypath);

	//Assigning vacancies to variables
	int Dancingvacancies;
	int Tennisvacancies;
	int Gamingvacancies;
	int Runningvacancies;
	int Swimmingvacancies;
	int Chessvacancies;
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
		if (v.getCCAID() == 'd' || v.getCCAID() == 'D') {
			Dancingvacancies = v.getvacancies();
			DancingCCA = v.getCCAName();
			dancingid = v.getCCAID();
		}
		if (v.getCCAID() == 't' || v.getCCAID() == 'T') {
			Tennisvacancies = v.getvacancies();
			TennisCCA = v.getCCAName();
			tennisid = v.getCCAID();
		}
		if (v.getCCAID() == 'g' || v.getCCAID() == 'G') {
			Gamingvacancies = v.getvacancies();
			GamingCCA = v.getCCAName();
			gamingid = v.getCCAID();
		}
		if (v.getCCAID() == 'r' || v.getCCAID() == 'R') {
			Runningvacancies = v.getvacancies();
			RunningCCA = v.getCCAName();
			runningid = v.getCCAID();
		}
		if (v.getCCAID() == 's' || v.getCCAID() == 'S') {
			Swimmingvacancies = v.getvacancies();
			SwimmingCCA = v.getCCAName();
			swimmingid = v.getCCAID();
		}
		if (v.getCCAID() == 'c' || v.getCCAID() == 'C') {
			Chessvacancies = v.getvacancies();
			ChessCCA = v.getCCAName();
			chessid = v.getCCAID();
		}
		if (v.getCCAID() == 'w' || v.getCCAID() == 'W') {
			specialcca = v.getCCAName();
		}
	}
	//cout << specialcca << endl;



	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(dancingid));
	vector<student_class> dancinglist = filelist.find1stClub(filelist, dancingid, Dancingvacancies);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(tennisid));
	vector<student_class> tennislist = filelist.find1stClub(filelist, tennisid, Tennisvacancies);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(gamingid));
	vector<student_class> gaminglist = filelist.find1stClub(filelist, gamingid, Gamingvacancies);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(runningid));
	vector<student_class> runninglist = filelist.find1stClub(filelist, runningid, Runningvacancies);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(swimmingid));
	vector<student_class> swimminglist = filelist.find1stClub(filelist, swimmingid, Swimmingvacancies);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(chessid));
	vector<student_class> chesslist = filelist.find1stClub(filelist, chessid, Chessvacancies);


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
	printingfxn(filelist.students);


	cout << "======================================================================" << endl;
	cout << "LIST OF GAMING LIST PEOPLE ROUND 1\n";

	printingfxn(gaminglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF DANCING LIST PEOPLE ROUND 1\n";

	printingfxn(dancinglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF CHESS LIST PEOPLE ROUND 1\n";

	printingfxn(chesslist);

	cout << "======================================================================" << endl;
	cout << "LIST OF RUNNING LIST PEOPLE ROUND 1\n";

	printingfxn(runninglist);
	cout << "======================================================================" << endl;
	cout << "LIST OF SWIMMING LIST PEOPLE ROUND 1\n";

	printingfxn(swimminglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF TENNIS LIST PEOPLE ROUND 1\n";

	printingfxn(tennislist);


	//Round 2
	vector<student_class> specialvector;
	vector<student_class> checkervector;
	int checkvac = 0;
	int count = 0;
	//Create a function to assign the id to search 
	//Checker is global
	if (specialcca == DancingCCA) {
		checker = dancingid;
		checkervector = dancinglist;
		checkvac = Dancingvacancies;

	}
	if (specialcca == TennisCCA) {
		checkervector = tennislist;
		checker = tennisid;
		checkvac = Tennisvacancies;
	}
	if (specialcca == GamingCCA) {
		checkervector = gaminglist;
		checker = gamingid;
		checkvac = Gamingvacancies;
	}
	if (specialcca == RunningCCA) {
		checkervector = runninglist;
		checker = runningid;
		checkvac = Runningvacancies;
	}
	if (specialcca == SwimmingCCA) {
		checkervector = swimminglist;
		checker = swimmingid;
		checkvac = Swimmingvacancies;
	}
	if (specialcca == ChessCCA) {
		checkervector = chesslist;
		checker = chessid;
		checkvac = Chessvacancies;
	}
	//cout << checkvac;
	//Checks for no. of 'Special' students in the vector holding the cca students
	cout << "==============================================" << endl;
	for (int i = 0; i < checkervector.size(); i++) {
		student_class s = checkervector.at(i);
		//test(s);
		if (s.getWinchoice1() >= '1') {
			count++;
		}
	}

	cout << "No. of students with win records in special sport: " << count << endl;
	//Checking chesscca for special students (students with wins in the special sport)
	//if vectorsize > vacacny

	if (count < 3) {
		for (int i = 0; i < gaminglist.size(); i++) {
			student_class s = gaminglist.at(i);
			if (specialcca == GamingCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < chesslist.size(); i++) {
			student_class s = chesslist.at(i);
			if (specialcca == ChessCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < tennislist.size(); i++) {
			student_class s = tennislist.at(i);
			if (specialcca == TennisCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < dancinglist.size(); i++) {
			student_class s = dancinglist.at(i);
			if (specialcca == DancingCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < runninglist.size(); i++) {
			student_class s = runninglist.at(i);
			if (specialcca == RunningCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
		for (int i = 0; i < swimminglist.size(); i++) {
			student_class s = swimminglist.at(i);
			if (specialcca == SwimmingCCA)
				break;
			if (s.getChoice2() == checker && s.getWinchoice2() >= 1 || s.getChoice3() == checker && s.getWinchoice3() >= 1) {
				specialvector.push_back(s);
			}
		}
	}

	cout << "---Potential Stolen Candidates--- " << endl;
	printingfxn(specialvector);


	cout << endl;
	vector<student_class> removal;

	cout << "=====================================" << endl;
	//Sorts by no.wins
	while (bool ender = true) {
		if (specialvector.size() == 0) {
			cout << "There are no potential stolen candidates..." << endl;
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
				gaminglist.push_back(specialvector[i]);
				removal.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			sort(gaminglist.begin(), gaminglist.end(), round2endsort);
			while (gaminglist.size() > Gamingvacancies)
				gaminglist.pop_back();
			checkervector = gaminglist;
			break;
		}
		if (checker == chessid) {
			for (int i = 0; i < specialvector.size(); i++) {
				chesslist.push_back(specialvector[i]);
				removal.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			sort(chesslist.begin(), chesslist.end(), round2endsort);
			while (chesslist.size() > Chessvacancies)
				chesslist.pop_back();
			checkervector = chesslist;
			break;
		}
		if (checker == tennisid) {
			for (int i = 0; i < specialvector.size(); i++) {
				tennislist.push_back(specialvector[i]);
				removal.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			sort(tennislist.begin(), tennislist.end(), round2endsort);
			while (tennislist.size() > Tennisvacancies)
				tennislist.pop_back();
			checkervector = tennislist;
			break;
		}
		if (checker == dancingid) {
			for (int i = 0; i < specialvector.size(); i++) {
				dancinglist.push_back(specialvector[i]);
				removal.push_back(specialvector[i]);
				cout << "adding";
				if (i + 1 >= adding) {
					break;
				}
			}
			sort(dancinglist.begin(), dancinglist.end(), round2endsort);
			while (dancinglist.size() > Dancingvacancies)
				dancinglist.pop_back();
			checkervector = dancinglist;
			break;
		}

		if (checker == runningid) {
			for (int i = 0; i < specialvector.size(); i++) {
				runninglist.push_back(specialvector[i]);
				removal.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			sort(runninglist.begin(), runninglist.end(), round2endsort);
			while (runninglist.size() > Runningvacancies)
				runninglist.pop_back();
			checkervector = runninglist;
			break;
		}

		if (checker == swimmingid) {
			for (int i = 0; i < specialvector.size(); i++) {
				swimminglist.push_back(specialvector[i]);
				removal.push_back(specialvector[i]);
				if (i + 1 >= adding) {
					break;
				}
			}
			
			sort(swimminglist.begin(), swimminglist.end(), round2endsort);
			while (swimminglist.size() > Swimmingvacancies)
				swimminglist.pop_back();
			checkervector = swimminglist;
			break;
		}
	}

	if (!removal.empty() && specialcca != ChessCCA) filelist.remainding_vector3(chesslist, removal);
	if (!removal.empty() && specialcca != GamingCCA) { filelist.remainding_vector3(gaminglist, removal);  }
	if (!removal.empty() && specialcca != SwimmingCCA) { filelist.remainding_vector3(swimminglist, removal); }
	if (!removal.empty() && specialcca != DancingCCA) { filelist.remainding_vector3(dancinglist, removal);  }
	if (!removal.empty() && specialcca != RunningCCA) filelist.remainding_vector3(runninglist, removal);
	if (!removal.empty() && specialcca != TennisCCA) filelist.remainding_vector3(tennislist, removal);



	cout << "=====================================" << endl;
	cout << "\n----Updated " << specialcca << " list--------\n";
	printingfxn(checkervector);







	cout << "======================================================================" << endl;
	cout << "Remaining students who have no given sport\n";


	if (gaminglist.size() > 0) { filelist.remainding_vector(filelist, gaminglist); }
	if (chesslist.size() > 0) { filelist.remainding_vector(filelist, chesslist); }
	if (dancinglist.size() > 0) { filelist.remainding_vector(filelist, dancinglist); }
	if (runninglist.size() > 0) { filelist.remainding_vector(filelist, runninglist); }
	if (swimminglist.size() > 0) { filelist.remainding_vector(filelist, swimminglist); }
	if (tennislist.size() > 0) { filelist.remainding_vector(filelist, tennislist); }

	printingfxn(filelist.students);

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(dancingid));
	vector<student_class> dancinglist_second = filelist.find2ndClub(filelist, dancingid, (Dancingvacancies - dancinglist.size()));

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(tennisid));
	vector<student_class> tennislist_second = filelist.find2ndClub(filelist, tennisid, (Tennisvacancies - tennislist.size()));

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(gamingid));
	vector<student_class> gaminglist_second = filelist.find2ndClub(filelist, gamingid, (Gamingvacancies - gaminglist.size()));

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(runningid));
	vector<student_class> runninglist_second = filelist.find2ndClub(filelist, runningid, (Runningvacancies - runninglist.size()));

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(swimmingid));
	vector<student_class> swimminglist_second = filelist.find2ndClub(filelist, swimmingid, (Swimmingvacancies - swimminglist.size()));

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(chessid));
	vector<student_class> chesslist_second = filelist.find2ndClub(filelist, chessid, (Chessvacancies - chesslist.size()));


	dancinglist.insert(dancinglist.end(), dancinglist_second.begin(), dancinglist_second.end());
	tennislist.insert(tennislist.end(), tennislist_second.begin(), tennislist_second.end());
	gaminglist.insert(gaminglist.end(), gaminglist_second.begin(), gaminglist_second.end());
	runninglist.insert(runninglist.end(), runninglist_second.begin(), runninglist_second.end());
	swimminglist.insert(swimminglist.end(), swimminglist_second.begin(), swimminglist_second.end());
	chesslist.insert(chesslist.end(), chesslist_second.begin(), chesslist_second.end());



	cout << "======================================================================" << endl;
	cout << "LIST OF GAMING LIST PEOPLE ROUND 3\n";

	printingfxn(gaminglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF DANCING LIST PEOPLE ROUND 3\n";

	printingfxn(dancinglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF CHESS LIST PEOPLE ROUND 3\n";

	printingfxn(chesslist);

	cout << "======================================================================" << endl;
	cout << "LIST OF RUNNING LIST PEOPLE ROUND 3\n";

	printingfxn(runninglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF SWIMMING LIST PEOPLE ROUND 3\n";

	printingfxn(swimminglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF TENNIS LIST PEOPLE ROUND 3\n";

	printingfxn(tennislist);


	if (gaminglist.size() > 0) { filelist.remainding_vector2(filelist, gaminglist); }
	if (chesslist.size() > 0) { filelist.remainding_vector2(filelist, chesslist); }
	if (dancinglist.size() > 0) { filelist.remainding_vector2(filelist, dancinglist); }
	if (runninglist.size() > 0) { filelist.remainding_vector2(filelist, runninglist); }
	if (swimminglist.size() > 0) { filelist.remainding_vector2(filelist, swimminglist); }
	if (tennislist.size() > 0) { filelist.remainding_vector2(filelist, tennislist); }

	cout << "======================================================================" << endl;
	cout << "LIST OF REMAINING PEOPLE AFTER ROUND 3\n";

	printingfxn(filelist.students);


	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(dancingid));
	vector<student_class> dancinglist_third = filelist.find3rdClub(filelist, dancingid, (Dancingvacancies - dancinglist.size()));

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(tennisid));
	vector<student_class> tennislist_third = filelist.find3rdClub(filelist, tennisid, (Tennisvacancies - tennislist.size()));

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(gamingid));
	vector<student_class> gaminglist_third = filelist.find3rdClub(filelist, gamingid, (Gamingvacancies - gaminglist.size()));

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(runningid));
	vector<student_class> runninglist_third = filelist.find3rdClub(filelist, runningid, (Runningvacancies - runninglist.size()));

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(swimmingid));
	vector<student_class> swimminglist_third = filelist.find3rdClub(filelist, swimmingid, (Swimmingvacancies - swimminglist.size()));

	sort(filelist.students.begin(), filelist.students.end(), sortbyCLUB_WINS(chessid));
	vector<student_class> chesslist_third = filelist.find3rdClub(filelist, chessid, (Chessvacancies - chesslist.size()));




	dancinglist.insert(dancinglist.end(), dancinglist_third.begin(), dancinglist_third.end());
	tennislist.insert(tennislist.end(), tennislist_third.begin(), tennislist_third.end());
	gaminglist.insert(gaminglist.end(), gaminglist_third.begin(), gaminglist_third.end());
	runninglist.insert(runninglist.end(), runninglist_third.begin(), runninglist_third.end());
	swimminglist.insert(swimminglist.end(), swimminglist_third.begin(), swimminglist_third.end());
	chesslist.insert(chesslist.end(), chesslist_third.begin(), chesslist_third.end());

	cout << "======================================================================" << endl;
	cout << "LIST OF GAMING LIST PEOPLE ROUND 4\n";

	printingfxn(gaminglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF DANCING LIST PEOPLE ROUND 4\n";

	printingfxn(dancinglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF CHESS LIST PEOPLE ROUND 4\n";

	printingfxn(chesslist);

	cout << "======================================================================" << endl;
	cout << "LIST OF RUNNING LIST PEOPLE ROUND 4\n";

	printingfxn(runninglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF SWIMMING LIST PEOPLE ROUND 4\n";

	printingfxn(swimminglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF TENNIS LIST PEOPLE ROUND 4\n";

	printingfxn(tennislist);


		if (gaminglist.size() > 0 && !filelist.students.empty()) { filelist.remainding_vector2(filelist, gaminglist); }
		if (chesslist.size() > 0 && !filelist.students.empty()) { filelist.remainding_vector2(filelist, chesslist); }
		if (dancinglist.size() > 0 && !filelist.students.empty()) { filelist.remainding_vector2(filelist, dancinglist); }
		if (runninglist.size() > 0 && !filelist.students.empty()) { filelist.remainding_vector2(filelist, runninglist); }
		if (swimminglist.size() > 0 && !filelist.students.empty()) { filelist.remainding_vector2(filelist, swimminglist); }
		if (tennislist.size() > 0 && !filelist.students.empty()) { filelist.remainding_vector2(filelist, tennislist); }
		
	else
	{
			cout << "======================================================================" << endl;
			cout << "LIST OF GAMING LIST PEOPLE ROUND 1\n";

			printingfxn(gaminglist);

			cout << "======================================================================" << endl;
			cout << "LIST OF DANCING LIST PEOPLE \n";

			printingfxn(dancinglist);

			cout << "======================================================================" << endl;
			cout << "LIST OF CHESS LIST PEOPLE \n";

			printingfxn(chesslist);

			cout << "======================================================================" << endl;
			cout << "LIST OF RUNNING LIST PEOPLE\n";

			printingfxn(runninglist);

			cout << "======================================================================" << endl;
			cout << "LIST OF SWIMMING LIST PEOPLE \n";

			printingfxn(swimminglist);

			cout << "======================================================================" << endl;
			cout << "LIST OF TENNIS LIST PEOPLE \n";

			printingfxn(tennislist);



		system("pause"); 
		return 0;
	}

	cout << "======================================================================" << endl;
	cout << "LIST OF PEOPLE WITH NO SPORT AFTER ROUND 4\n";

	if (filelist.students.empty())
	{
		return 0;
	}
	printingfxn(filelist.students);

	cout << "======================================================================" << endl;
	cout << "Round 5 - Random sorting time!\n";

	sort(filelist.students.begin(), filelist.students.end(), sortbyGPA());

	srand(time(0)); //This is to set a random seed for the RNG (random number generator)

	do {
		int rng = rand() % 6; //randomly sets a number from 0 to 5
		switch (rng)
		{
		case 0: //case when rolled for Dancing (number = 0)
			//Code for assigning student into dancing (Not yet implimented)
			if (dancinglist.size() < Dancingvacancies)
			{
				dancinglist.push_back(filelist.students.back());
				cout << "\nSent to Dancing" << endl;
				test(*(filelist.students.end() - 1));
				filelist.students.pop_back();
				
				break;
			}
			else
			{
				cout << "\nNo vacancies in Dancing" << endl;
				
				break;
			}

		case 1: //case when rolled for Tennis (number = 1)
			//Code for assigning student into tennis (Not yet implimented)
			if (tennislist.size() < Tennisvacancies)
			{
				tennislist.push_back(filelist.students.back());
				cout << "\nSent to Tennis" << endl;
				test(*(filelist.students.end() - 1));
				filelist.students.pop_back();
				
				break;
			}
			else
			{
				cout << "\nNo vacancies in Tennis" << endl;
				
				break;
			}

		case 2: //case when rolled for Gaming (number = 2)
			//Code for assigning student into gaming (Not yet implimented)
			if (gaminglist.size() < Gamingvacancies)
			{
				gaminglist.push_back(filelist.students.back());
				cout << "\nSent to Gaming" << endl;
				test(*(filelist.students.end() - 1));
				filelist.students.pop_back();
				
				break;
			}
			else
			{
				cout << "\nNo vacancies in Gaming" << endl;
				
				break;
			}

		case 3: //case when rolled for Running (number = 3)
			//Code for assigning student into running (Not yet implimented)
			if (runninglist.size() < Runningvacancies)
			{
				runninglist.push_back(filelist.students.back());
				cout << "\nSent to Running" << endl;
				test(*(filelist.students.end() - 1));
				filelist.students.pop_back();
				
				break;
			}
			else
			{
				cout << "\nNo vacancies in Running" << endl;
				
				break;
			}

		case 4: //case when rolled for Swimming (number = 4)
			//Code for assigning student into swimming (Not yet implimented)
			if (swimminglist.size() < Swimmingvacancies)
			{
				swimminglist.push_back(filelist.students.back());
				cout << "\nSent to Swimming" << endl;
				test(*(filelist.students.end() - 1));
				filelist.students.pop_back();
				
				break;
			}
			else
			{
				cout << "\nNo vacancies in Swimming" << endl;
				
				break;
			}

		case 5: //case when rolled for Chess (number =5)
			//Code for assigning student into chess (Not yet implimented)
			if (chesslist.size() < Chessvacancies)
			{
				chesslist.push_back(filelist.students.back());
				cout << "\nSent to Chess" << endl;
				test(*(filelist.students.end() - 1));
				filelist.students.pop_back();
				
				break;
			}
			else
			{
				cout << "\nNo vacancies in Chess" << endl;
				
				break;
			}

		default: //default case when RNG doesnt go right.. Should not be the case
			cout << "Error in the random number genrator.. Please check Round 5's code" << endl;
			break;

		}
	}while (filelist.students.size() != 0);

	cout << "======================================================================" << endl;
	cout << "LIST OF GAMING LIST PEOPLE ROUND 1\n";

	printingfxn(gaminglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF DANCING LIST PEOPLE \n";

	printingfxn(dancinglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF CHESS LIST PEOPLE \n";

	printingfxn(chesslist);

	cout << "======================================================================" << endl;
	cout << "LIST OF RUNNING LIST PEOPLE\n";

	printingfxn(runninglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF SWIMMING LIST PEOPLE \n";

	printingfxn(swimminglist);

	cout << "======================================================================" << endl;
	cout << "LIST OF TENNIS LIST PEOPLE \n";

	printingfxn(tennislist);


	system("pause");
	return 0;
}
